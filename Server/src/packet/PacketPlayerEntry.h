/**
 * @file PacketPlayerEntry.h
 * @brief プレイヤー出現パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETPLAYERENTRY_H__
#define __PACKETPLAYERENTRY_H__

#include "YanaPOnlineUtil/Packet/Packet.h"
#include "YanaPOnlineUtil/Stream/MemoryStream.h"
#include "type.h"
#include "PlayerData.h"
#include "PacketID.h"


using namespace YanaPOnlineUtil::Packet;
using namespace YanaPOnlineUtil::Stream;

/**
 * @brief プレイヤー出現パケット
 */
class PacketPlayerEntry : public CPacket
{

public:
	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual unsigned char GetPacketId() const override { return PacketID::PlayerEntry; }

	

	//! データ
	PlayerData Data;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPlayerEntry()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPlayerEntry(PlayerData InData)
	{
		Data = InData;
		
	}

	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(IMemoryStream *pStream)
	{
		if (!Data.Serialize(pStream)) { return false; }
		
		return true;
	}
};

#endif // #ifndef __PACKETPLAYERENTRY_H__
