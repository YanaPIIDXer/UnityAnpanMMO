/**
 * @file PacketAreaChange.h
 * @brief エリア切り替え要求パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETAREACHANGE_H__
#define __PACKETAREACHANGE_H__

#include "YanaPOnlineUtil/Packet/Packet.h"
#include "YanaPOnlineUtil/Stream/MemoryStream.h"
#include "type.h"
#include "PacketID.h"


using namespace YanaPOnlineUtil::Packet;
using namespace YanaPOnlineUtil::Stream;

/**
 * @brief エリア切り替え要求パケット
 */
class PacketAreaChange : public CPacket
{

public:
	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual unsigned char GetPacketId() const override { return PacketID::AreaChange; }

	

	//! エリアID
	uint AreaId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketAreaChange()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketAreaChange(uint InAreaId)
	{
		AreaId = InAreaId;
		
	}

	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(IMemoryStream *pStream)
	{
		if(!pStream->Serialize(&AreaId)) { return false; }
		
		return true;
	}
};

#endif // #ifndef __PACKETAREACHANGE_H__
