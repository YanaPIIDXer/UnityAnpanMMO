/**
 * @file PacketPlayerMoved.h
 * @brief プレイヤーが移動したパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETPLAYERMOVED_H__
#define __PACKETPLAYERMOVED_H__

#include "YanaPOnlineUtil/Packet/Packet.h"
#include "YanaPOnlineUtil/Stream/MemoryStream.h"
#include "type.h"
#include "PositionPack.h"
#include "PacketID.h"


using namespace YanaPOnlineUtil::Packet;
using namespace YanaPOnlineUtil::Stream;

/**
 * @brief プレイヤーが移動したパケット
 */
class PacketPlayerMoved : public CPacket
{

public:
	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual unsigned char GetPacketId() const override { return PacketID::PlayerMoved; }

	

	//! ID
	uint Id;
	//! 移動データ
	PositionPack Position;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPlayerMoved()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPlayerMoved(uint InId, PositionPack InPosition)
	{
		Id = InId;
		Position = InPosition;
		
	}

	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(IMemoryStream *pStream)
	{
		if(!pStream->Serialize(&Id)) { return false; }
		if (!Position.Serialize(pStream)) { return false; }
		
		return true;
	}
};

#endif // #ifndef __PACKETPLAYERMOVED_H__
