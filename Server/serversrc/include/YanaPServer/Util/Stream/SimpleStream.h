#ifndef __SIMPLESTREAM_H__
#define __SIMPLESTREAM_H__

namespace YanaPServer
{
namespace Util
{
namespace Stream
{

/**
 * @class CSimpleStream
 * @brief 単純なストリーム
 * @detail Appendするたびに内部でnewとdeleteが走るので注意。
 */
class CSimpleStream
{

public:

	/**
	 * @brief コンストラクタ
	 */
	CSimpleStream();

	/**
	 * @brief デストラクタ
	 */
	~CSimpleStream();

	/**
	 * @fn void AppendString(const char *pStr)
	 * @brief 文字列追加
	 * @param[in] pStr 追加する文字列
	 */
	void AppendString(const char *pStr);

	/**
	 * @fn void AppendLine(const char *pStr)
	 * @brief 末尾に改行コードを付加して文字列追加
	 * @param[in] pStr 追加する文字列
	 */
	void AppendStringLine(const char *pStr);

	/**
	 * @fn void AppendBinary(const char *pData, unsigned int Size)
	 * @brief バイナリ追加
	 * @param[in] pData データ
	 * @param[in] Size データ長
	 */
	void AppendBinary(const char *pData, unsigned int Size);

	/**
	 * @fn const char *GetBuffer() const
	 * @brief 文字列取得
	 * @return 文字列
	 */
	const char *Get() const { return pBuffer; }

	/**
	 * @fn unsigned int GetLength() const
	 * @brief 文字列長取得
	 * @return 文字列長
	 */
	unsigned int GetLength() const { return Length; }

private:

	// バッファ
	char *pBuffer;

	// 文字列長.
	unsigned int Length;

};

}
}
}

#endif		// #ifndef __SIMPLESTREAM_H__
