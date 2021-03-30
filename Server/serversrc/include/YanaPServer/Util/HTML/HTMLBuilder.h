#ifndef __HTMLBUILDER_H__
#define __HTMLBUILDER_H__

#include <string>
#include "HTMLObject.h"
#include <vector>

namespace YanaPServer
{
namespace Util
{
namespace HTML
{

/**
 * @class CHTMLBuilder
 * @brief ＨＴＭＬ構築クラス
 */
class CHTMLBuilder
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] InTitle ページのタイトル
	 */
	CHTMLBuilder(const std::string &InTitle);

	/**
	 * @デストラクタ
	 */
	~CHTMLBuilder();

	/**
	 * @fn std::string Generate() const
	 * @brief 構築
	 * @return 構築されたHTML
	 */
	std::string Generate() const;

	/**
	 * @fn void AddText(const std::string &Text, bool bAppendNewLine)
	 * @brief テキスト追加
	 * @param[in] Textテキスト
	 * @param[in] bAppendNewLine 改行するか？
	 * @return テキストオブジェクト
	 */
	CHTMLText *AddText(const std::string &Text, bool bAppendNewLine = true);

	/**
	 * @fn void AddLink(const char *pURL, const char *pText, bool bAppendNewLine)
	 * @brief リンク追加
	 * @param[in] pURL URL
	 * @param[in] pText テキスト
	 * @param[in] bAppendNewLine 改行するか？
	 * @return リンクオブジェクト
	 */
	CHTMLLink *AddLink(const char *pURL, const char *pText, bool bAppendNewLine = true);

	/**
	 * @fn CHTMLForm *AddFormAsPOST(const char *pActionTarget)
	 * @brief POSTメソッドでフォーム追加
	 * @param[in] pActionTarget アクションターゲット
	 * @return フォームオブジェクトへのポインタ
	 */
	CHTMLForm *AddFormAsPOST(const char *pActionTarget)
	{
		return AddForm(CHTMLForm::EMethod::POST, pActionTarget);
	}

	/**
	 * @fn CHTMLForm *AddFormAsGET(const char *pActionTarget)
	 * @brief GETメソッドでフォーム追加
	 * @param[in] pActionTarget アクションターゲット
	 * @return フォームオブジェクトへのポインタ
	 */
	CHTMLForm *AddFormAsGET(const char *pActionTarget)
	{
		return AddForm(CHTMLForm::EMethod::GET, pActionTarget);
	}

	/**
	 * @fn CHTMLTable *AddTable(int Border = 1)
	 * @brief テーブル追加
	 * @param[in] Border ボーダーライン
	 * @return テーブルオブジェクト
	 */
	CHTMLTable *AddTable(int Border = 1);

	/**
	 * @fn CHTMLStyle *AddStyle()
	 * @brief スタイル追加
	 * @return スタイルオブジェクト
	 */
	CHTMLStyle *AddStyle();

	/**
	 * @fn CHTMLScript *AddScript(const char *pScriptType = "text/javascript")
	 * @brief スクリプト追加
	 * @param[in] pScriptType スクリプトのタイプ
	 * @return スクリプトオブジェクト
	 */
	CHTMLScript *AddScript(const char *pScriptType = "text/javascript");

	/**
	 * @fn void AddHeaderObject(IHTMLObject)
	 * @brief ヘッダオブジェクト追加
	 * @param[in] pObject オブジェクト
	 */
	void AddHeaderObject(IHTMLObject *pObject)
	{
		HTMLObjectSharedPtr pPtr(pObject);
		HeaderObjects.push_back(pPtr);
	}

	/**
	 * @fn void AddBodyObject(IHTMLObject)
	 * @brief ボディオブジェクト追加
	 * @param[in] pObject オブジェクト
	 */
	void AddBodyObject(IHTMLObject *pObject)
	{
		HTMLObjectSharedPtr pPtr(pObject);
		BodyObjects.push_back(pPtr);
	}

private:

	// ページのタイトル
	std::string Title;

	// ヘッダオブジェクト群.
	std::vector<HTMLObjectSharedPtr> HeaderObjects;

	// ボディオブジェクト群.
	std::vector<HTMLObjectSharedPtr> BodyObjects;


	// フォーム追加.
	CHTMLForm *AddForm(CHTMLForm::EMethod Method, const char *pActionTarget);

};

}
}
}

#endif		// #ifndef __HTMLBUILDER_H__
