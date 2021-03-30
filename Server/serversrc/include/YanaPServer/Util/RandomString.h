#ifndef __RANDOMSTRING_H__
#define __RANDOMSTRING_H__

namespace YanaPServer
{
namespace Util
{

/**
 * @class CRandomString
 * @brief ランダム文字列
 */
class CRandomString
{

public:

	/**
	 * @brief コンストラクタ
	 */
	CRandomString();

	/**
	 * @brief デストラクタ
	 */
	~CRandomString();

	/**
	 * @fn void Generate(unsigned int Length)
	 * @brief 生成
	 * @param[in] Length 文字列長
	 * @param[in] bIsHex １６進数の文字列か？
	 */
	void Generate(unsigned int Length, bool bIsHex = false);

	/**
	 * @fn const char *Get() const
	 * @brief 取得
	 * @return 生成されたランダム文字列
	 */
	const char *Get() const { return pStr; }

private:

	// 文字セット
	static const char *pCharSet;

	// 文字列
	char *pStr;

};

}
}

#endif		// #ifndef __RANDOMSTRING_H__
