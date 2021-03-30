#ifndef __HTMLOBJECT_H__
#define __HTMLOBJECT_H__

#include <string>
#include <vector>
#include <memory>
#include <map>

namespace YanaPServer
{
namespace Util
{
namespace HTML
{

/**
 * @class IHTMLObject
 * @brief HTMLの要素インタフェース
 */
class IHTMLObject
{

public:

	/**
	 * @brief デストラクタ
	 */
	virtual ~IHTMLObject() {}

	/**
	 * @fn virtual void Generate(std::string &OutCode) const = 0
	 * @brief 構築
	 * @param[out] OutCode 構築されたHTMLコード
	 */
	virtual void Generate(std::string &OutCode) const = 0;

};

typedef std::shared_ptr<IHTMLObject> HTMLObjectSharedPtr;

/**
 * @class CHTMLText
 * @brief 単純なHTMLテキスト
 */
class CHTMLText : public IHTMLObject
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] InText テキストデータ
	 * @param[in] bAppendNewLine 改行するか？
	 */
	CHTMLText(const std::string &InText, bool bAppendNewLine = true)
		: Text(InText)
	{
		if (bAppendNewLine)
		{
			Text += "<br />";
		}
	}

	/**
	 * @brief デストラクタ
	 */
	virtual ~CHTMLText() {}

	/**
	 * @fn virtual void Generate(std::string &OutCode) const override
	 * @brief 構築
	 * @param[out] OutCode 構築されたHTMLコード
	 */
	virtual void Generate(std::string &OutCode) const override
	{
		OutCode += Text;
		OutCode += "\n";
	}

private:

	// テキストデータ
	std::string Text;

};

/**
 * @class CHTMLLink
 * @brief 他ページへのリンク
 */
class CHTMLLink : public IHTMLObject
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] pInURL URL
	 * @param[in] pInText 表示するテキスト
	 * @param[in] bInAppendNewLine 改行するか？
	 */
	CHTMLLink(const char *pInURL, const char *pInText, bool bInAppendNewLine = true)
		: pURL(pInURL)
		, pText(pInText)
		, pClickEvent(nullptr)
		, bAppendNewLine(bInAppendNewLine)
	{
	}

	/**
	 * @brief デストラクタ
	 */
	virtual ~CHTMLLink() {}

	/**
	 * @fn void SetClickEvent(const char *pInClickEvent)
	 * @brief クリックイベントを設定
	 * @param[in] pInClickEvent クリックイベント
	 */
	void SetClickEvent(const char *pInClickEvent) { pClickEvent = pInClickEvent; }

	/**
	 * @fn virtual void Generate(std::string &OutCode) const override
	 * @brief 構築
	 * @param[out] OutCode 構築されたHTMLコード
	 */
	virtual void Generate(std::string &OutCode) const override
	{
		OutCode += "<a href=\"";
		OutCode += pURL;
		OutCode += "\"";
		if (pClickEvent != nullptr)
		{
			OutCode += " onclick=\"";
			OutCode += pClickEvent;
			OutCode += "\"";
		}
		OutCode += ">";
		OutCode += pText;
		OutCode += "</a>";
		if (bAppendNewLine)
		{
			OutCode += "<br />\n";
		}
	}

private:

	// URL
	const char *pURL;

	// テキスト
	const char *pText;

	// クリックイベント
	const char *pClickEvent;

	// 改行するか？
	bool bAppendNewLine;

};

/**
 * @class CHTMLForm
 * @brief HTMLフォーム
 */
class CHTMLForm : public IHTMLObject
{

public:

	/**
	 * @enum EMethod
	 * @brief HTMLメソッド
	 */
	enum class EMethod
	{
		POST,
		GET,
	};

	/**
	 * @brief コンストラクタ
	 * @param[in] InMethod HTMLメソッド
	 * @param[in] pInActionTarget アクションターゲット
	 */
	CHTMLForm(EMethod InMethod, const char *pInActionTarget)
		: Method(InMethod)
		, pActionTarget(pInActionTarget)
	{
	}

	/**
	 * @brief デストラクタ
	 */
	virtual ~CHTMLForm()
	{
	}

	/**
	 * @fn void AddObject(IHTMLObject *pObject)
	 * @brief オブジェクト追加
	 * @param[in] pObject HTMLオブジェクト
	 */
	void AddObject(IHTMLObject *pObject)
	{
		HTMLObjectSharedPtr pPtr(pObject);
		Objects.push_back(pPtr);
	}

	/**
	 * @fn void AddText(const char *pText, bool bAppendNewLine = false)
	 * @brief 単純なテキストを追加
	 * @param[in] pText テキスト
	 * @param[in] bAppendNewLine 改行するか？
	 */
	void AddText(const char *pText, bool bAppendNewLine = false)
	{
		CHTMLText *pObject = new CHTMLText(pText, bAppendNewLine);
		AddObject(pObject);
	}

	/**
	 * @fn void AddTextBox(const char *pName, const char *pDefaultValue = "", bool bAppendNewLine = true)
	 * @brief テキストボックスを追加
	 * @param[in] pName テキストボックスに付ける名前
	 * @param[in] pDefaultValue デフォルト値
	 * @param[in] bAppendNewLine 改行するか？
	 */
	void AddTextBox(const char *pName, const char *pDefaultValue = "", bool bAppendNewLine = true)
	{
		CHTMLText *pText = MakeTextBox(pName, pDefaultValue, bAppendNewLine);
		AddObject(pText);
	}

	/**
	 * @fn static CHTMLText *MakeTextBox(const char *pName, const char *pDefaultValue = "", bool bAppendNewLine = true)
	 * @brief テキストボックスを生成
	 * @param[in] pName テキストボックスに付ける名前
	 * @param[in] pDefaultValue デフォルト値
	 * @param[in] bAppendNewLine 改行するか？
	 * @return CHTMLTextオブジェクト
	 */
	static CHTMLText *MakeTextBox(const char *pName, const char *pDefaultValue = "", bool bAppendNewLine = true);

	/**
	 * @fn void AddCheckBox(const char *pName, bool bDefaultChecked = false, bool bAppendNewLine = true)
	 * @brief チェックボックスを追加
	 * @param[in] pName チェックボックスに付ける名前
	 * @param[in] pValue 値
	 * @param[in] bDefaultChecked デフォルトでチェックされている状態にするか？
	 * @param[in] bAppendNewLine 改行するか？
	 */
	void AddCheckBox(const char *pName, const char *pValue = nullptr, bool bDefaultChecked = false, bool bAppendNewLine = true)
	{
		CHTMLText *pText = MakeCheckBox(pName, pValue, bDefaultChecked, bAppendNewLine);
		AddObject(pText);
	}

	/**
	 * @fn static CHTMLText *MakeCheckBox(const char *pName, const char *pValue = nullptr, bool bDefaultValue = false, bool bAppendNewLine = true)
	 * @brief チェックボックスを生成
	 * @param[in] pName チェックボックスに付ける名前
	 * @param[in] pValue 値
	 * @param[in] bDefaultChecked デフォルトでチェックされている状態にするか？
	 * @param[in] bAppendNewLine 改行するか？
	 * @return CHTMLTextオブジェクト
	 */
	static CHTMLText *MakeCheckBox(const char *pName, const char *pValue = nullptr, bool bDefaltChecked = false, bool bAppendNewLine = true);
	
	/**
	 * @fn void AddSubmitButton(const char *pName, const char *pValue, bool bAppendNewLine = true)
	 * @brief 送信ボタンを追加
	 * @param[in] pName 送信ボタンに付ける名前
	 * @param[in] pValue デフォルト値
	 * @param[in] bAppendNewLine 改行するか？
	 */
	void AddSubmitButton(const char *pName, const char *pValue, bool bAppendNewLine = true)
	{
		CHTMLText *pText = MakeSubmitButton(pName, pValue, bAppendNewLine);
		AddObject(pText);
	}

	/**
	 * @fn static CHTMLText *MakeCheckBox(const char *pName, bool bDefaultValue = false, bool bAppendNewLine = true)
	 * @brief 送信ボタンを生成
	 * @param[in] pName 送信ボタンに付ける名前
	 * @param[in] bValue 表示文字列
	 * @param[in] bAppendNewLine 改行するか？
	 * @return CHTMLTextオブジェクト
	 */
	static CHTMLText *MakeSubmitButton(const char *pName, const char *pValue, bool bAppendNewLine = true);

	/**
	 * @fn virtual void Generate(std::string &OutCode) const override
	 * @brief 構築
	 * @param[out] OutCode 構築されたHTMLコード
	 */
	virtual void Generate(std::string &OutCode) const override;

private:

	// メソッド
	EMethod Method;

	// ターゲット
	const char *pActionTarget;

	// オブジェクト群
	std::vector<HTMLObjectSharedPtr> Objects;

};

/**
 * @class CHTMLTable
 * @brief HTMLテーブル
 */
class CHTMLTable : public IHTMLObject
{

public:

	/**
	 * @class CColumn
	 * @brief カラム
	 */
	class CColumn
	{
		
	public:

		/**
		 * @brief コンストラクタ
		 * @param[in] pInName カラム名
		 */
		CColumn(const char *pInName)
			: pName(pInName)
		{
		}

		/**
		 * @brief デストラクタ
		 */
		~CColumn()
		{
		}

		/**
		 * @fn const char *GetName() const
		 * @brief カラム名を取得
		 * @return カラム名
		 */
		const char *GetName() const { return pName; }

		/**
		 * @fn void AddItem(const char *pText)
		 * @brief 要素追加
		 * @param[in] pText 文字列
		 */
		void AddItem(const char *pText)
		{
			CHTMLText *pObject = new CHTMLText(pText, false);
			AddItem(pObject);
		}

		/**
		 * @fn void AddItem(IHTMLObject *pObject)
		 * @brief 要素追加
		 * @param[in] pObject オブジェクト
		 */
		void AddItem(IHTMLObject *pObject)
		{
			HTMLObjectSharedPtr pPtr(pObject);
			Objects.push_back(pPtr);
		}

		/**
		 * @fn unsigned int GetObjectCount() const
		 * @brief オブジェクトの個数を取得
		 * @return オブジェクトの個数
		 */
		unsigned int GetObjectCount() const { return Objects.size(); }

		/**
		 * @fn std::string GetCode(unsigned int Index) const
		 * @brief HTMLコード取得
		 * @param[in] Index インデックス
		 * @return HTMLコード
		 */
		std::string GetCode(unsigned int Index) const
		{
			std::string Code = "";
			if (Index < Objects.size())
			{
				Objects[Index]->Generate(Code);
			}
			return Code;
		}

	private:

		// カラム名.
		const char *pName;

		// オブジェクト群
		std::vector<HTMLObjectSharedPtr> Objects;

	};

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] InBorder ボーダーライン
	 */
	CHTMLTable(int InBorder = 1)
		: Border(InBorder)
	{
	}

	/**
	 * @brief デストラクタ
	 */
	virtual ~CHTMLTable()
	{
		for (auto *pColumn : Columns)
		{
			delete pColumn;
		}
		Columns.clear();
	}

	/**
	 * @fn CColumn *AddColumn(const char *pColumnName)
	 * @brief カラム追加
	 * @param[in] pColumnName カラム名
	 * @return カラムオブジェクト
	 */
	CColumn *AddColumn(const char *pColumnName)
	{
		CColumn *pColumn = new CColumn(pColumnName);
		Columns.push_back(pColumn);
		return pColumn;
	}

	/**
	 * @fn virtual void Generate(std::string &OutCode) const override
	 * @brief 構築
	 * @param[out] OutCode 構築されたHTMLコード
	 */
	virtual void Generate(std::string &OutCode) const override;

private:

	// ボーダーライン
	int Border;

	// カラムリスト
	std::vector<CColumn *> Columns;

};

/**
 * @class CHTMLStyle
 * @brief スタイルシート
 */
class CHTMLStyle : public IHTMLObject
{

public:

	/**
	 * @class CObject
	 * @brief オブジェクト
	 */
	class CObject
	{

	public:

		/**
		 * @brief コンストラクタ
		 */
		CObject() {}

		/**
		 * @brief デストラクタ
		 */
		~CObject() {}

		/**
		 * @fn void SetParameter(const char *pName, const char *pValue)
		 * @brief パラメータを設定
		 * @param[in] pProperty プロパティ
		 * @param[in] pValue 値
		 */
		void SetParameter(const char *pProperty, const char *pValue)
		{
			Params[pProperty] = pValue;
		}

		/**
		 * @fn void Generate(std::string &OutCode) const
		 * @brief コード生成
		 * @param[out] OutCode 生成されたコード
		 */
		void Generate(std::string &OutCode) const;

	private:

		// パラメータ
		std::map<std::string, std::string> Params;

	};

private:	// 別名定義.

	typedef std::shared_ptr<CObject> ObjectPtr;

public:

	/**
	 * @brief コンストラクタ
	 */
	CHTMLStyle() {}

	/**
	 * @brief デストラクタ
	 */
	virtual ~CHTMLStyle() {}

	/**
	 * @fn CObject *AddObject(const char *pName)
	 * @brief オブジェクト追加
	 * @param[in] pSelector セレクタ
	 * @return オブジェクト
	 */
	CObject *AddObject(const char *pSelector)
	{
		CObject *pObj = new CObject();
		ObjectPtr pPtr = ObjectPtr(pObj);
		Objects[pSelector] = pPtr;
		return pObj;
	}

	/**
	 * @fn virtual void Generate(std::string &OutCode) const override
	 * @brief 構築
	 * @param[out] OutCode 構築されたHTMLコード
	 */
	virtual void Generate(std::string &OutCode) const override;

private:

	// オブジェクトマップ
	std::map<std::string, ObjectPtr> Objects;

};

/**
 * @class CHTMLScript
 * @brief スクリプト
 */
class CHTMLScript : public IHTMLObject
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] pInType タイプ
	 */
	CHTMLScript(const char *pInType)
		: pType(pInType)
		, Code("")
	{
	}

	/**
	 * @brief デストラクタ
	 */
	virtual ~CHTMLScript() {}

	/**
	 * @fn void AddCode(const std::string &CodeStr)
	 * @brief コード追加
	 * @param[in] CodeStrコード文字列
	 */
	void AddCode(const std::string &CodeStr)
	{
		Code += CodeStr + "\n";
	}

	/**
	 * @fn void AddFunction(const char *pFunctionName, const std::string &CodeStr)
	 * @brief 関数追加
	 * @param[in] pFunctionName 関数名
	 * @param[in] pArgs 引数群
	 * @param[in] CodeStr コード文字列
	 */
	void AddFunction(const char *pFunctionName, const char *pArgs, const std::string &CodeStr);
	
	/**
	 * @fn virtual void Generate(std::string &OutCode) const override
	 * @brief 構築
	 * @param[out] OutCode 構築されたHTMLコード
	 */
	virtual void Generate(std::string &OutCode) const override;

private:

	// タイプ
	const char *pType;

	// コード
	std::string Code;

};

}
}
}

#endif		// #ifndef __HTMLOBJECT_H__
