#ifndef __PACKET_H__
#define __PACKET_H__

#include "Serializable/Serializable.h"
#include "Stream/MemoryStream.h"

namespace YanaPOnlineUtil
{
namespace Packet
{

/**
 * @class CPacket
 * @brief パケット基底クラス
 */
class CPacket : public Serializable::ISerializable
{

public:

	/**
	 * @brief コンストラクタ
	 */
	CPacket() {}

	/**
	 * @brief デストラクタ
	 */
	virtual ~CPacket() {}

	/**
	 * @fn virtual unsigned char GetPacketId() const = 0
	 * @brief パケットＩＤ取得
	 * @return パケットＩＤ
	 */
	virtual unsigned char GetPacketId() const = 0;

};

}
}

#endif		// #ifndef __PACKET_H__
