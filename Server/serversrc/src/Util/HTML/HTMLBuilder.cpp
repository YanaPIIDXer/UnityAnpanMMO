#include "Util/HTML/HTMLBuilder.h"

namespace YanaPServer
{
namespace Util
{
namespace HTML
{

// �R���X�g���N�^
CHTMLBuilder::CHTMLBuilder(const std::string &InTitle)
	: Title(InTitle)
{
}

// �f�X�g���N�^
CHTMLBuilder::~CHTMLBuilder()
{
}

// �\�z.
std::string CHTMLBuilder::Generate() const
{
	std::string HTML;

	HTML += "<html>\n";

	HTML += "<head>\n";
	HTML += "<title>" + Title + "</title>\n";
	for (const auto &pObject : HeaderObjects)
	{
		pObject->Generate(HTML);
	}
	HTML += "</head>\n";

	HTML += "<body>\n";
	for (const auto &pObject : BodyObjects)
	{
		pObject->Generate(HTML);
	}
	HTML += "</body>\n";

	HTML += "</html>\n";

	return HTML;
}

// �e�L�X�g�ǉ�.
CHTMLText *CHTMLBuilder::AddText(const std::string &Text, bool bAppendNewLine)
{
	CHTMLText *pText = new CHTMLText(Text, bAppendNewLine);
	AddBodyObject(pText);

	return pText;
}

// �����N�ǉ�.
CHTMLLink *CHTMLBuilder::AddLink(const char *pURL, const char *pText, bool bAppendNewLine)
{
	CHTMLLink *pLink = new CHTMLLink(pURL, pText, bAppendNewLine);
	AddBodyObject(pLink);

	return pLink;
}

// �e�[�u���ǉ�.
CHTMLTable *CHTMLBuilder::AddTable(int Border)
{
	CHTMLTable *pTable = new CHTMLTable(Border);
	AddBodyObject(pTable);

	return pTable;
}

// �X�^�C���ǉ�.
CHTMLStyle *CHTMLBuilder::AddStyle()
{
	CHTMLStyle *pStyle = new CHTMLStyle();
	AddHeaderObject(pStyle);

	return pStyle;
}

// �X�N���v�g�ǉ�.
CHTMLScript *CHTMLBuilder::AddScript(const char *pScriptType)
{
	CHTMLScript *pScript = new CHTMLScript(pScriptType);
	AddHeaderObject(pScript);
	return pScript;
}


// �t�H�[���ǉ�.
CHTMLForm *CHTMLBuilder::AddForm(CHTMLForm::EMethod Method, const char *pActionTarget)
{
	CHTMLForm *pForm = new CHTMLForm(Method, pActionTarget);
	AddBodyObject(pForm);
	return pForm;
}

}
}
}
