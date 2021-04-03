#ifndef __CMemoryStreamWriter_H__
#define __CMemoryStreamWriter_H__

#include "MemoryStream.h"
#include "../Serializable/Serializable.h"

namespace YanaPOnlineUtil
{
namespace Stream
{

/**
 * @class CMemoryStreamWriter
 * @brief 書き込み用ストリーム
 */
class CMemoryStreamWriter : public IMemoryStream
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] InBufferSize バッファサイズ
	 */
	CMemoryStreamWriter(unsigned int InBufferSize);

	/**
	 * @brief デストラクタ
	 */
	virtual ~CMemoryStreamWriter();

	/**
	 * @fn virtual bool Serialize(int *pData) = 0
	 * @brief intのシリアライズ
	 * @param[in] pData データ
	 * @return 成功したらtrueを返す。
	 */
	virtual bool Serialize(int *pData) override;

	/**
	 * @fn virtual bool Serialize(unsigned int *pData) override
	 * @brief unsigned intのシリアライズ
	 * @param[in] pData データ
	 * @return 成功したらtrueを返す。
	 */
	virtual bool Serialize(unsigned int *pData) override;

	/**
	 * @fn virtual bool Serialize(short *pData) override
	 * @brief shortのシリアライズ
	 * @param[in] pData データ
	 * @return 成功したらtrueを返す。
	 */
	virtual bool Serialize(short *pData) override;

	/**
	 * @fn virtual bool Serialize(unsigned short *pData) override
	 * @brief unsigned shortのシリアライズ
	 * @param[in] pData データ
	 * @return 成功したらtrueを返す。
	 */
	virtual bool Serialize(unsigned short *pData) override;

	/**
	 * @fn virtual bool Serialize(char *pData) override
	 * @brief charのシリアライズ
	 * @param[in] pData データ
	 * @return 成功したらtrueを返す。
	 */
	virtual bool Serialize(char *pData) override;

	/**
	 * @fn virtual bool Serialize(unsigned char *pData) override
	 * @brief unsigned charのシリアライズ
	 * @param[in] pData データ
	 * @return 成功したらtrueを返す。
	 */
	virtual bool Serialize(unsigned char *pData) override;

	/**
	 * @fn virtual bool Serialize(float *pData) override
	 * @brief floatのシリアライズ
	 * @param[in] pData データ
	 * @return 成功したらtrueを返す。
	 */
	virtual bool Serialize(float *pData) override;

	/**
	 * @fn virtual bool Serialize(std::string *pData) override
	 * @brief 文字列のシリアライズ
	 * @param[in] pData データ
	 * @return 成功したらtrueを返す。
	 */
	virtual bool Serialize(std::string *pData) override;

	/**
	 * @fn virtual bool Serialize(Serializable::ISerializable *pData) override
	 * @brief シリアライズ可能なオブジェクトのシリアライズ
	 * @param[in] pData データ
	 * @return 成功したらtrueを返す。
	 */
	virtual bool Serialize(Serializable::ISerializable *pData) override { return pData->Serialize(this); }

	/**
	 * @fn virtual bool Serialize(void *pData, unsigned int DataSize) override
	 * @brief 任意のデータをシリアライズ
	 * @param[in] pData データ
	 * @param[in] DataSize データ長
	 * @return 成功したらtrueを返す。
	 */
	virtual bool Serialize(void *pData, unsigned int DataSize) override { return Write(pData, DataSize); }

	/**
	 * @fn virtual bool IsError() const override
	 * @brief エラーが発生しているか？
	 * @return エラーが発生していたらtrueを返す。
	 */
	virtual bool IsError() const override { return bIsError; }

	/**
	 * @fn virtual bool IsLeftData() const override
	 * @brief 読み込んでいないデータが残っているか？
	 * @return 残っていたらtrueを返す。
	 */
	virtual bool IsLeftData() const override { return (CurrentPosition < BufferSize); }

	/**
	 * @fn virtual EStreamType GetType() const override
	 * @brief ストリームタイプを取得
	 * @return ストリームタイプ返す。
	 */
	virtual EStreamType GetType() const override { return EStreamType::Write; }

	/**
	 * @fn const char *GetBuffer() const
	 * @brief バッファを取得。
	 * @detail バッファの先頭位置を返す。
	 * @return バッファ
	 */
	const char *GetBuffer() const { return pBuffer; }

	/**
	 * @fn unsigned int GetSize() const
	 * @brief サイズを取得
	 * @return サイズ
	 */
	unsigned int GetSize() const { return CurrentPosition; }

	/**
	 * @fn void Reset()
	 * @brief リセット
	 */
	void Reset()
	{
		CurrentPosition = 0;
		bIsError = false;
	}

private:

	// バッファ
	char *pBuffer;

	// バッファサイズ
	unsigned int BufferSize;

	// 現在の位置.
	unsigned int CurrentPosition;

	// エラーが起きているか？
	bool bIsError;


	// 書き込み
	bool Write(const void *pData, unsigned int Size);

};

}
}

#endif		// #ifndef __CMemoryStreamWriter_H__
