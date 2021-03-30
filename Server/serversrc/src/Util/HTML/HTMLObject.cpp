#include "Util/HTML/HTMLObject.h"
#include <sstream>
#include <algorithm>

namespace YanaPServer
{
namespace Util
{
namespace HTML
{

// =============== CHTMLForm =====================

// �e�L�X�g�{�b�N�X�𐶐�.
CHTMLText *CHTMLForm::MakeTextBox(const char *pName, const char *pDefaultValue, bool bAppendNewLine)
{
	std::string Code = "<input type=\"text\" name=\"";
	Code += pName;
	Code += "\" value=\"";
	Code += pDefaultValue;
	Code += "\">";

	CHTMLText *pText = new CHTMLText(Code, bAppendNewLine);
	return pText;
}

// �`�F�b�N�{�b�N�X�𐶐�.
CHTMLText *CHTMLForm::MakeCheckBox(const char *pName, const char *pValue, bool bDefaltChecked, bool bAppendNewLine)
{
	std::string Code = "<input type=\"checkbox\" name=\"";
	Code += pName;
	Code += "\"";
	if (pValue != nullptr)
	{
		Code += " value=\"";
		Code += pValue;
		Code += "\"";
	}
	if (bDefaltChecked)
	{
		Code += " checked=\"checked\"";
	}
	Code += ">";

	CHTMLText *pText = new CHTMLText(Code, bAppendNewLine);
	return pText;
}

// ���M�{�^���𐶐�.
CHTMLText *CHTMLForm::MakeSubmitButton(const char *pName, const char *pValue, bool bAppendNewLine)
{
	std::string Code = "<input type=\"submit\" name=\"";
	Code += pName;
	Code += "\" value=\"";
	Code += pValue;
	Code += "\">";

	CHTMLText *pText = new CHTMLText(Code, bAppendNewLine);
	return pText;
}

// �\�z.
void CHTMLForm::Generate(std::string &OutCode) const
{
	OutCode += "<form method=\"";
	switch (Method)
	{
		case EMethod::POST:

			OutCode += "POST\"";
			break;

		case EMethod::GET:

			OutCode += "GET\"";
			break;
	}

	OutCode += " action=\"";
	OutCode += pActionTarget;
	OutCode += "\">\n";

	std::string FormCode = "\t";
	for (const auto &pObject : Objects)
	{
		pObject->Generate(FormCode);
	}
	// ���`.
	auto Pos = FormCode.find("\n");
	while (Pos != std::string::npos)
	{
		FormCode.replace(Pos, 1, "\n\t");
		Pos = FormCode.find("\n", Pos + 2);
	}
	Pos = FormCode.find_last_of("\n\t");
	if (Pos != std::string::npos)
	{
		FormCode.replace(Pos, 2, "");
	}

	OutCode += FormCode;

	OutCode += "</form>\n";
}


// ================== CHTMLTable ===================

// �\�z.
void CHTMLTable::Generate(std::string &OutCode) const
{
	std::stringstream Stream;
	Stream << "<table border=";
	Stream << Border;
	Stream << ">\n";
	OutCode += Stream.str();

	OutCode += "\t<tr>\n";
	for (const auto *pColumn : Columns)
	{
		OutCode += "\t\t<th>";
		OutCode += pColumn->GetName();
		OutCode += "</th>\n";
	}
	OutCode += "\t</tr>\n";

	unsigned int Count = 0;
	for (const auto *pColumn : Columns)
	{
		Count = std::max<unsigned int>(Count, pColumn->GetObjectCount());
	}

	for (unsigned int i = 0; i < Count; i++)
	{
		OutCode += "\t<tr>\n";
		for (const auto *pColumn : Columns)
		{
			OutCode += "\t\t<td>";
			std::string ColumnCode = pColumn->GetCode(i);

			// ���`.
			// �}�������\�[�X�R�[�h��̉��s��S�ēP���B
			auto Pos = ColumnCode.find("\n");
			while (Pos != std::string::npos)
			{
				ColumnCode.replace(Pos, 1, "");
				Pos = ColumnCode.find("\n", Pos);
			}
			
			OutCode += ColumnCode;
			OutCode += "</td>\n";
		}
		OutCode += "\t</tr>\n";
	}

	OutCode += "</table>\n";
}

// ============== CHTMLStyle ==============

// �\�z.
void CHTMLStyle::Generate(std::string &OutCode) const
{
	OutCode += "<style>\n";

	for (const auto &It : Objects)
	{
		OutCode += "\t" + It.first + " {\n";
		It.second->Generate(OutCode);
		OutCode += "\t}\n";
	}

	OutCode += "</style>\n";
}

// �R�[�h����.
void CHTMLStyle::CObject::Generate(std::string &OutCode) const
{
	for (const auto &It : Params)
	{
		OutCode += "\t\t" + It.first + ": " + It.second + ";\n";
	}
}

// ================== CHTMLScript =======================

// �֐��ǉ�.
void CHTMLScript::AddFunction(const char *pFunctionName, const char *pArgs, const std::string &CodeStr)
{
	std::string Str = "function ";
	Str += pFunctionName;
	Str += "(";
	Str += pArgs;
	Str += ")\n{\n\t";

	std::string Tmp = CodeStr;
	// ���`.
	auto Pos = Tmp.find("\n");
	while (Pos != std::string::npos)
	{
		Tmp.replace(Pos, 1, "\n\t");
		Pos = Tmp.find("\n", Pos + 2);
	}
	Str += Tmp;
	Str += "\n}";

	AddCode(Str);
}

// �\�z.
void CHTMLScript::Generate(std::string &OutCode) const
{
	OutCode += "<script type=\"";
	OutCode += pType;
	OutCode += "\">\n\t";

	std::string CodeStr = Code;
	auto Pos = CodeStr.find("\n");
	while (Pos != std::string::npos)
	{
		CodeStr.replace(Pos, 1, "\n\t");
		Pos = CodeStr.find("\n", Pos + 2);
	}
	Pos = CodeStr.find_last_of("\n\t");
	if (Pos != std::string::npos)
	{
		CodeStr.replace(Pos, 2, "");
	}

	OutCode += CodeStr;
	OutCode += "</script>\n";
}

}
}
}
