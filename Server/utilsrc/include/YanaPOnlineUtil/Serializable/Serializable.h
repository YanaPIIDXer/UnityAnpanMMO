#ifndef __SERIALIZABLE_H__
#define __SERIALIZABLE_H__

namespace YanaPOnlineUtil
{
namespace Stream
{
class IMemoryStream;
}
namespace Serializable
{

/**
 * @class ISerializable
 * @brief シリアライズ用インタフェース
 */
class ISerializable
{

public:

	/**
	 * @brief デストラクタ
	 */
	virtual ~ISerializable() {}

	/**
	 * @fn virtual bool Serialize(Stream::IMemoryStream *pStream) = 0
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す
	 */
	virtual bool Serialize(Stream::IMemoryStream *pStream) = 0;

};

}
}

#endif		// #ifndef __SERIALIZABLE_H__
