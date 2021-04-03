#ifndef __PACKETHEADER_H__
#define __PACKETHEADER_H__

#include "Serializable/Serializable.h"
#include "Packet.h"

namespace YanaPOnlineUtil
{
namespace Packet
{

/**
 * @class CPacketHeader
 * @brief パケットヘッダ
 */
class CPacketHeader : public Serializable::ISerializable
{

public:

	/**
	 * @brief コンストラクタ
	 */
	CPacketHeader();
	
	/**
	 * @brief コンストラクタ
	 * @param[in] InPacketId パケットＩＤ
	 * @param[in] InSize サイズ
	 */
	CPacketHeader(unsigned char InPacketId, unsigned char InSize);
	
	/**
	 * @brief デストラクタ
	 */
	virtual ~CPacketHeader() {}

	/**
	 * @fn unsigned char GetPacketId() const
	 * @brief パケットＩＤ取得
	 * @return パケットＩＤ
	 */
	unsigned char GetPacketId() const { return PacketId; }

	/**
	 * @fn unsigned char GetSize() const
	 * @brief サイズ取得
	 * @return サイズ
	 */
	unsigned char GetSize() const { return Size; }

	/**
	 * @fn virtual bool Serialize(Util::Stream::IMemoryStream *pStream) override
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	virtual bool Serialize(Stream::IMemoryStream *pStream) override;

	//! ヘッダサイズ
	static const unsigned int HeaderSize;

private:

	// パケットＩＤ
	unsigned char PacketId;

	// サイズ
	unsigned char Size;

};

}
}

#endif		// #ifndef __PACKETHEADER_H__
