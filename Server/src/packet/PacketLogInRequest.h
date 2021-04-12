/**
 * @file PacketLogInRequest.h
 * @brief LogInRequestパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETLOGINREQUEST_H__
#define __PACKETLOGINREQUEST_H__

#include "YanaPOnlineUtil/Packet/Packet.h"
#include "YanaPOnlineUtil/Stream/MemoryStream.h"
#include "type.h"
#include "PacketID.h"


using namespace YanaPOnlineUtil::Packet;
using namespace YanaPOnlineUtil::Stream;

/**
 * @brief LogInRequestパケット
 */
class PacketLogInRequest  : public CPacket
{

public:
	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual unsigned char GetPacketId() const override { return PacketID::LogInRequest; }

	

	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketLogInRequest()
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

#endif // #ifndef __PACKETLOGINREQUEST_H__
