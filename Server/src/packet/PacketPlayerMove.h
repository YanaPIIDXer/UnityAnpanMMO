/**
 * @file PacketPlayerMove.h
 * @brief プレイヤー移動パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETPLAYERMOVE_H__
#define __PACKETPLAYERMOVE_H__

#include "YanaPOnlineUtil/Packet/Packet.h"
#include "YanaPOnlineUtil/Stream/MemoryStream.h"
#include "type.h"
#include "PositionPack.h"
#include "PacketID.h"


using namespace YanaPOnlineUtil::Packet;
using namespace YanaPOnlineUtil::Stream;

/**
 * @brief プレイヤー移動パケット
 */
class PacketPlayerMove : public CPacket
{

public:
	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual unsigned char GetPacketId() const override { return PacketID::PlayerMove; }

	

	//! 移動データ
	PositionPack Position;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPlayerMove()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPlayerMove(PositionPack InPosition)
	{
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
		if (!Position.Serialize(pStream)) { return false; }
		
		return true;
	}
};

#endif // #ifndef __PACKETPLAYERMOVE_H__
