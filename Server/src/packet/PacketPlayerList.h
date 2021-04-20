/**
 * @file PacketPlayerList.h
 * @brief プレイヤーリストパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETPLAYERLIST_H__
#define __PACKETPLAYERLIST_H__

#include "YanaPOnlineUtil/Packet/Packet.h"
#include "YanaPOnlineUtil/Stream/MemoryStream.h"
#include "type.h"
#include "util/FlexArray.h"
#include "PlayerData.h"
#include "PacketID.h"


using namespace YanaPOnlineUtil::Packet;
using namespace YanaPOnlineUtil::Stream;

/**
 * @brief プレイヤーリストパケット
 */
class PacketPlayerList : public CPacket
{

public:
	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual unsigned char GetPacketId() const override { return PacketID::PlayerList; }

	

	//! データリスト
	FlexArray<PlayerData> List;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPlayerList()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPlayerList(FlexArray<PlayerData> InList)
	{
		List = InList;
		
	}

	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(IMemoryStream *pStream)
	{
		if (!List.Serialize(pStream)) { return false; }
		
		return true;
	}
};

#endif // #ifndef __PACKETPLAYERLIST_H__
