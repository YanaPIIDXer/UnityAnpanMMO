/**
 * @file PacketPing.h
 * @brief Pingパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETPING_H__
#define __PACKETPING_H__

#include "YanaPOnlineUtil/Packet/Packet.h"
#include "YanaPOnlineUtil/Stream/MemoryStream.h"
#include "PacketID.h"


using namespace YanaPOnlineUtil::Packet;
using namespace YanaPOnlineUtil::Stream;

/**
 * @brief Pingパケット
 */
class PacketPing  : public CPacket
{

public:
	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual unsigned char GetPacketId() const override { return PacketID::Ping; }

	

	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPing()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	

	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(IMemoryStream *pStream)
	{
		
		return true;
	}
};

#endif // #ifndef __PACKETPING_H__
