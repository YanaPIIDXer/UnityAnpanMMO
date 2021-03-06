using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace NativePacketGenerator
{
	/// <summary>
	/// ソース生成.
	/// </summary>
	public class ClientSourceGenerator
	{
		
		/// <summary>
		/// クラスデータ
		/// </summary>
		private ClassData Class = null;

		/// <summary>
		/// テンプレートファイル名.
		/// </summary>
		private static readonly string TemplateFileName = "templates\\client\\Template.cs";

		/// <summary>
		/// コンストラクタテンプレート名.
		/// </summary>
		private static readonly string ConstructorTemplateFileName = "templates\\client\\Constructor.cs";

		/// <summary>
		/// 置換結果.
		/// </summary>
		private string Result = "";

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="InClass">クラスデータ</param>
		/// <param name="InOutputPath">出力先</param>
		public ClientSourceGenerator(ClassData InClass)
		{
			Class = InClass;
		}

		/// <summary>
		/// 生成.
		/// </summary>
		/// <returns>成功したらtrue</returns>
		public bool Generate()
		{
			try
			{
				string Template = ReadFromFile(TemplateFileName);
				Result = ParseTag(Template);
			} catch(Exception e)
			{
				Console.WriteLine(e.Message);
				return false;
			}
			return true;
		}

		/// <summary>
		/// ファイルから読み込み
		/// </summary>
		/// <param name="FileName">ファイル名</param>
		/// <returns>読み込んだテキスト</returns>
		private string ReadFromFile(string FileName)
		{
			StreamReader Reader = new StreamReader(FileName, Encoding.GetEncoding("UTF-8"));
			string Result = Reader.ReadToEnd();
			Reader.Close();
			return Result;
		}

		/// <summary>
		/// 書き出し
		/// </summary>
		/// <param name="TargetPath">パス</param>
		/// <returns>成功したらtrue</returns>
		public bool Write(string TargetPath)
		{
			var OutputPath = TargetPath + "\\" + Class.ClassName + ".cs";
			try
			{
				string LoadedSrc = "";
				if(File.Exists(OutputPath))
				{
					using (StreamReader Reader = new StreamReader(OutputPath, Encoding.GetEncoding("UTF-8")))
					{
						LoadedSrc = Reader.ReadToEnd();
					}
				}
				
				// ファイル名はここで置換.
				Result = Result.Replace("$FILE_NAME$", Path.GetFileName(OutputPath));

				using (StreamWriter Writer = new StreamWriter(OutputPath, false, Encoding.GetEncoding("UTF-8")))
				{
					Writer.Write(Result);
				}
			}
			catch(Exception e)
			{
				Console.Error.WriteLine(e.Message);
				return false;
			}
			return true;
		}

		/// <summary>
		/// タグ解析.
		/// </summary>
		/// <param name="Template">テンプレート</param>
		/// <returns>タグ解析結果</returns>
		private string ParseTag(string Template)
		{
			// コンストラクタ。
			// メンバが無ければ消滅する。
			string Constructor = "";
			if (Class.Members.Count > 0)
			{
				Constructor = ReadFromFile(ConstructorTemplateFileName);
			}
			Template = Template.Replace("$CONSTRUCTOR$", Constructor);

			// インクルードガード
			Template = Template.Replace("$INCLUDE_GUARD$", "__" + Class.ClassName.ToUpper() + "_H__");

			// クラスコメント
			Template = Template.Replace("$CLASS_COMMENT$", Class.Comment);

			// クラス名.
			Template = Template.Replace("$CLASS_NAME$", Class.ClassName);

			// 基底クラス名.
			string BaseClassName = "";
			if (Class.IsPureClass)
			{
				BaseClassName = "YanaPOnlineUtil.ISerializable";
			}
			else
			{
				BaseClassName = Class.BaseClassName;
			}
			if (BaseClassName == "Packet")
			{
				BaseClassName = "YanaPOnlineUtil.Packet.Packet";
			}
			BaseClassName = ": " + BaseClassName;
			Template = Template.Replace("$BASE_CLASS_NAME$", BaseClassName);

			// パケットＩＤ
			string FunctionStr = "";
			if(Class.BaseClassName == "Packet")
			{
				FunctionStr = "public override byte PacketId { get { return (byte)" + Class.ScopeName + "." + Class.PacketID + "; } }";
			}
			Template = Template.Replace("$GET_PACKET_ID_FUNCTION$", FunctionStr);

			// enum
			string Enums = "";
			foreach(var KeyValue in Class.EnumList)
			{
				Enums += "public enum " + KeyValue.Key + "\n\t{\n";
				foreach(var Data in  Class.EnumList[KeyValue.Key])
				{
					Enums += "\t\t//! " + Data.Comment + "\n";
					Enums += "\t\t" + Data.Name;
					Enums += ",\n";
				}
				Enums += "\t};";
			}
			Template = Template.Replace("$ENUMS$", Enums);

			// メンバ変数.
			string Members = "";
			for(int i = 0; i < Class.Members.Count; i++)
			{
				var MemberData = Class.Members[i];
				Members += "//! " + MemberData.Comment + "\n\t";
				Members += "public " + MemberData.TypeName + " " + MemberData.Name + " = new " + MemberData.TypeName + "();\n\t";
			}
			Template = Template.Replace("$MEMBERS$", Members);

			// コンストラクタのメンバ
			string ConstructorMembers = "";
			if(Class.IsProcessPacket)
			{
				ConstructorMembers += "uint InClientId";
				if(Class.Members.Count > 0)
				{
					ConstructorMembers += ", ";
				}
			}
			if (Class.Members.Count > 0)
			{
				for (int i = 0; i < Class.Members.Count - 1; i++)
				{
					var MemberData = Class.Members[i];
					ConstructorMembers += MemberData.TypeName + " In" + MemberData.Name + ", ";
				}
				ConstructorMembers += Class.Members.Last().TypeName + " In" + Class.Members.Last().Name;
			}
			Template = Template.Replace("$CONSTRUCTOR_MEMBERS$", ConstructorMembers);

			// メンバを押し込む
			string PutMembers = "";
			if(Class.IsProcessPacket)
			{
				PutMembers += "ClientId = InClientId;\n\t\t";
			}
			for (int i = 0; i < Class.Members.Count; i++)
			{
				PutMembers += Class.Members[i].Name + " = In" + Class.Members[i].Name + ";\n\t\t";
			}
			Template = Template.Replace("$PUT_MEMBERS$", PutMembers);

			string SerializeMethod = "";
			if (Class.BaseClassName == "Packet")
			{
				SerializeMethod = "public override bool Serialize(IMemoryStream Stream)";
			}
			else
			{
				SerializeMethod = "public bool Serialize(IMemoryStream Stream)";
			}
			Template = Template.Replace("$SERIALIZE_METHOD$", SerializeMethod);

			string SerializeFunctions = "";
			for(int i = 0; i < Class.Members.Count; i++)
			{
				var Member = Class.Members[i];
				if(Member.IsPrimitive)
				{
					SerializeFunctions += "if(!Stream.Serialize(ref " + Member.Name + ")) { return false; }\n\t\t";
				}
				else
				{
					SerializeFunctions += "if (!" + Member.Name + ".Serialize(Stream)) { return false; }\n\t\t";
				}
			}
			Template = Template.Replace("$SERIALIZE_MEMBERS$", SerializeFunctions);

			return Template;
		}

	}
}
