/**
 * @file PlayerData.h
 * @brief プレイヤーデータパケット
 * @author NativePacketGenerator
 */

#ifndef __PLAYERDATA_H__
#define __PLAYERDATA_H__

#include "YanaPOnlineUtil/Packet/Packet.h"
#include "YanaPOnlineUtil/Stream/MemoryStream.h"
#include "type.h"
#include "PositionPack.h"
#include "YanaPOnlineUtil/Serializable/Serializable.h"

using namespace YanaPOnlineUtil::Packet;
using namespace YanaPOnlineUtil::Stream;

/**
 * @brief プレイヤーデータパケット
 */
class PlayerData : public YanaPOnlineUtil::Serializable::ISerializable
{

public:
	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	

	

	//! ID
	uint Id;
	//! 座標
	PositionPack Position;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PlayerData()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PlayerData(uint InId, PositionPack InPosition)
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

#endif // #ifndef __PLAYERDATA_H__
