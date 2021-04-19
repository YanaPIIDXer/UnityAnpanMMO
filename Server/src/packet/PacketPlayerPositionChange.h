/**
 * @file PacketPlayerPositionChange.h
 * @brief プレイヤー位置変更パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETPLAYERPOSITIONCHANGE_H__
#define __PACKETPLAYERPOSITIONCHANGE_H__

#include "YanaPOnlineUtil/Packet/Packet.h"
#include "YanaPOnlineUtil/Stream/MemoryStream.h"
#include "type.h"
#include "PositionPack.h"
#include "PacketID.h"


using namespace YanaPOnlineUtil::Packet;
using namespace YanaPOnlineUtil::Stream;

/**
 * @brief プレイヤー位置変更パケット
 */
class PacketPlayerPositionChange : public CPacket
{

public:
	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual unsigned char GetPacketId() const override { return PacketID::PlayerPositionChange; }

	

	//! 座標
	PositionPack Position;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPlayerPositionChange()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPlayerPositionChange(PositionPack InPosition)
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

#endif // #ifndef __PACKETPLAYERPOSITIONCHANGE_H__
