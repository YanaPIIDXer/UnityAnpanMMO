/**
 * @file PacketEnemyEntry.h
 * @brief エネミー出現パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETENEMYENTRY_H__
#define __PACKETENEMYENTRY_H__

#include "YanaPOnlineUtil/Packet/Packet.h"
#include "YanaPOnlineUtil/Stream/MemoryStream.h"
#include "type.h"
#include "PositionPack.h"
#include "PacketID.h"


using namespace YanaPOnlineUtil::Packet;
using namespace YanaPOnlineUtil::Stream;

/**
 * @brief エネミー出現パケット
 */
class PacketEnemyEntry  : public CPacket
{

public:
	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual unsigned char GetPacketId() const override { return PacketID::EnemyEntry; }

	

	//! 座標
	PositionPack Position;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketEnemyEntry()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketEnemyEntry(PositionPack InPosition)
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
		Position.Serialize(pStream);
		
		return true;
	}
};

#endif // #ifndef __PACKETENEMYENTRY_H__
