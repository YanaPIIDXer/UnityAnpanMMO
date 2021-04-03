#ifndef __MEMORYSIZECALICULATOR_H__
#define __MEMORYSIZECALICULATOR_H__

#include "MemoryStream.h"
#include "../Serializable/Serializable.h"

namespace YanaPOnlineUtil
{
namespace Stream
{

/**
 * @class CMemorySizeCaliculator
 * @brief サイズ計算ストリーム
 */
class CMemorySizeCaliculator : public IMemoryStream
{

public:

	/**
	 * @brief コンストラクタ
	 */
	CMemorySizeCaliculator();

	/**
	 * @brief デストラクタ
	 */
	virtual ~CMemorySizeCaliculator() {}

	/**
	 * @fn virtual bool Serialize(int *pData) override
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
	virtual bool Serialize(void *pData, unsigned int DataSize) override
	{
		Size += DataSize;
		return true;
	}

	/**
	 * @fn virtual bool IsError() const override
	 * @brief エラーが発生しているか？
	 * @return エラーなんて無いので常にfalseを返す。
	 */
	virtual bool IsError() const override { return false; }

	/**
	 * @fn virtual bool IsLeftData() const override
	 * @brief 読み込んでいないデータが残っているか？
	 * @return 読み込むデータなんて無いので常にfalseを返す。
	 */
	virtual bool IsLeftData() const override { return false; }

	/**
	 * @fn virtual EStreamType GetType() const override
	 * @brief ストリームタイプを取得
	 * @return ストリームタイプ返す。
	 */
	virtual EStreamType GetType() const override { return EStreamType::CalcSize; }

	/**
	 * @fn unsigned int GetSize() const
	 * @brief サイズ取得
	 * @return サイズ
	 */
	unsigned int GetSize() const { return Size; }

private:

	// サイズ
	unsigned int Size;

};

}
}

#endif		// #ifndef __MEMORYSIZECALICULATOR_H__
