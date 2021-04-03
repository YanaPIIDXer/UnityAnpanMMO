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

			ServerIDEnumGenerator ServerIDGen = new ServerIDEnumGenerator(Classes);
			if (!ServerIDGen.Generate(0, "PacketID")) { return; }
			if (!ServerIDGen.Write(ServerPath + "\\PacketID.h")) { return; }
			ClientIDEnumGenerator ClientIDGen = new ClientIDEnumGenerator(Classes);
			if (!ClientIDGen.Generate(0, "PacketID")) { return; }
			if (!ClientIDGen.Write(ClientPath + "\\PacketID.cs")) { return; }

			foreach (var Class in Classes)
			{
				Console.Write(Class.ClassName + "の出力中・・・");
				// サーバ
				ServerSourceGenerator ServerGen = new ServerSourceGenerator(Class);
				if (!ServerGen.Generate())
				{
					Console.Write("");
					Console.WriteLine("サーバ側ソースコードの生成に失敗しました。");
					return;
				}
				if (!ServerGen.Write(ServerPath))
				{
					Console.Write("");
					Console.WriteLine("ゲームサーバへのソースコード書き込みに失敗しました。");
					return;
				}
				// クライアント
				ClientSourceGenerator ClientGen = new ClientSourceGenerator(Class);
				if (!ClientGen.Generate())
				{
					Console.Write("");
					Console.WriteLine("クライアント側ソースコードの生成に失敗しました。");
					return;
				}
				if (!ClientGen.Write(ClientPath))
				{
					Console.Write("");
					Console.WriteLine("クライアントへのソースコード書き込みに失敗しました。");
					return;
				}
				Console.WriteLine("OK");
			}
		}
	}
}
