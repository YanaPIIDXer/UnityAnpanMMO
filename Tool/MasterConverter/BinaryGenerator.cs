﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace MasterConverter
{

	/// <summary>
	/// バイナリ生成クラス
	/// </summary>
	public class BinaryGenerator
	{

		/// <summary>
		/// マスタ名.
		/// </summary>
		private string MasterName;

		/// <summary>
		/// マスタデータ
		/// </summary>
		private MasterData Master;
		
		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InMasterName">マスタ名</param>
		/// <param name="InMaster">マスタデータ</param>
		public BinaryGenerator(string InMasterName, MasterData InMaster)
		{
			MasterName = InMasterName;
			Master = InMaster;
		}

		/// <summary>
		/// 生成.
		/// </summary>
		/// <returns>成功したらtrueを返す</returns>
		public bool Generate()
		{
			try
			{
				string FilePath = Config.TemporaryDirectoryPath + "\\" + MasterName + ".bin";
				FileStream WriteStream = new FileStream(FilePath, FileMode.Create);
				using (BinaryWriter BinWriter = new BinaryWriter(WriteStream))
				{
					// シート数.
					{
						byte[] Bytes = BitConverter.GetBytes(Master.SheetCount);
						if(BitConverter.IsLittleEndian)
						{
							Bytes = Bytes.Reverse().ToArray();
							BinWriter.Write(Bytes);
						}
					}
					for (int Sheet = 0; Sheet < Master.SheetCount; Sheet++)
					{
						var Columns = Master.GetColumns(Sheet);
						// カラム数.
						{
							byte[] Bytes = BitConverter.GetBytes(Columns[0].DataList.Count);
							if (BitConverter.IsLittleEndian)
							{
								Bytes = Bytes.Reverse().ToArray();
								BinWriter.Write(Bytes);
							}
						}
						for (int i = 0; i < Columns[0].DataList.Count; i++)
						{
							for (int j = 0; j < Columns.Count; j++)
							{
								byte[] Bytes = null;
								double Data = 0.0;
								if (Columns[j].DataType != Type.String)
								{
									int EnumValue = 0;
									if (Master.TryFindEnumValue(Columns[j].DataList[i].ToString(), out EnumValue))
									{
										Data = EnumValue;
									}
									else
									{
										Data = (double)Columns[j].DataList[i];
									}
								}
								switch (Columns[j].DataType)
								{
									case Type.s8:

										// @HACK:負数ブチ込んだ時に問題起きる気がする・・・
										Bytes = new byte[1];
										Bytes[0] = (byte)Data;
										break;

									case Type.u8:

										Bytes = new byte[1];
										Bytes[0] = (byte)Data;
										break;

									case Type.s16:

										Bytes = BitConverter.GetBytes((short)Data);
										break;

									case Type.u16:

										Bytes = BitConverter.GetBytes((ushort)Data);
										break;

									case Type.s32:

										Bytes = BitConverter.GetBytes((int)Data);
										break;

									case Type.u32:

										Bytes = BitConverter.GetBytes((uint)Data);
										break;

									case Type.Float:

										Bytes = BitConverter.GetBytes((float)Data);
										break;

									case Type.String:

										string Str = (string)Columns[j].DataList[i];
										int StrSize = Encoding.UTF8.GetByteCount(Str);
										byte[] SizeBytes = BitConverter.GetBytes(StrSize);
										if (BitConverter.IsLittleEndian)
										{
											SizeBytes = SizeBytes.Reverse().ToArray();
										}
										BinWriter.Write(SizeBytes);
										Bytes = Encoding.UTF8.GetBytes(Str).Reverse().ToArray();
										break;
								}
								if (BitConverter.IsLittleEndian)
								{
									Bytes = Bytes.Reverse().ToArray();
								}

								BinWriter.Write(Bytes);
							}
						}

					}
				}
			}
			catch
			{
				return false;
			}

			return true;
		}

	}
}
