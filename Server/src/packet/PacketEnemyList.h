/**
 * @file PacketEnemyList.h
 * @brief エネミーリストパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETENEMYLIST_H__
#define __PACKETENEMYLIST_H__

#include "YanaPOnlineUtil/Packet/Packet.h"
#include "YanaPOnlineUtil/Stream/MemoryStream.h"
#include "type.h"
#include "util/FlexArray.h"
#include "EnemyData.h"
#include "PacketID.h"


using namespace YanaPOnlineUtil::Packet;
using namespace YanaPOnlineUtil::Stream;

/**
 * @brief エネミーリストパケット
 */
class PacketEnemyList  : public CPacket
{

public:
	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual unsigned char GetPacketId() const override { return PacketID::EnemyList; }

	

	//! データリスト
	FlexArray<EnemyData> List;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketEnemyList()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketEnemyList(FlexArray<EnemyData> InList)
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
		List.Serialize(pStream);
		
		return true;
	}
};

#endif // #ifndef __PACKETENEMYLIST_H__
