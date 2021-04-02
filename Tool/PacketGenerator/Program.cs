using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace NativePacketGenerator
{
	class Program
	{
		/// <summary>
		/// 設定ファイル名.
		/// </summary>
		private static readonly string SettingFileName = "NativePacketGenerator.ini";

		static void Main(string[] args)
		{
			if(!File.Exists(SettingFileName))
			{
				StreamWriter Writer = new StreamWriter(SettingFileName);
				Writer.WriteLine("Server Directory:");
				Writer.WriteLine("Client Directory:");
				Writer.Close();
				Console.WriteLine("設定ファイルが存在しなかったので自動生成しました。\n必要な項目を入力してください。");
				return;
			}

			StreamReader Reader = new StreamReader(SettingFileName);
			var ServerPath = Reader.ReadLine().Replace("Server Directory:", "");
			var ClientPath = Reader.ReadLine().Replace("Client Directory:", "");

			var Excels = Directory.GetFiles("PacketData");
			List<ClassData> Classes = new List<ClassData>();
			foreach(var Excel in Excels)
			{
				ExcelParser Parser = new ExcelParser(Excel);
				if(!Parser.Parse())
				{
					Console.Error.WriteLine(Excel + "のパースに失敗しました。");
					return;
				}
				foreach(var Class in Parser.Classes)
				{
					Classes.Add(Class);
					if (Class.IsPureClass) { continue; }
					Class.Includes.Add("PacketID.h");
				}
			}

			IDEnumGenerator GameServerIDGen = new IDEnumGenerator(Classes);
			if (!GameServerIDGen.Generate(0, "PacketID")) { return; }
			if (!GameServerIDGen.Write(ServerPath + "\\PacketID.h")) { return; }
			if (!GameServerIDGen.Write(ClientPath + "\\PacketID.h")) { return; }

			foreach (var Class in Classes)
			{
				Console.WriteLine(Class.ClassName + "の出力中・・・");
				ServerSourceGenerator ServerGen = new ServerSourceGenerator(Class);
				if (!ServerGen.Generate())
				{
					Console.WriteLine("ソースコードの生成に失敗しました。");
					return;
				}
				// サーバ
				if (!ServerGen.Write(ServerPath))
				{
					Console.WriteLine("ゲームサーバへのソースコード書き込みに失敗しました。");
					return;
				}
				ClientSourceGenerator ClientGen = new ClientSourceGenerator(Class);
				// クライアント
				if (!ClientGen.Write(ClientPath))
				{
					Console.WriteLine("クライアントへのソースコード書き込みに失敗しました。");
					return;
				}
			}

		}
	}
}
