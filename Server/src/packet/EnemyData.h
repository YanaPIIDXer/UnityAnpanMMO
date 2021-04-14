﻿/**
 * @file EnemyData.h
 * @brief エネミーデータパケット
 * @author NativePacketGenerator
 */

#ifndef __ENEMYDATA_H__
#define __ENEMYDATA_H__

#include "YanaPOnlineUtil/Packet/Packet.h"
#include "YanaPOnlineUtil/Stream/MemoryStream.h"
#include "type.h"
#include "PositionPack.h"
#include "YanaPOnlineUtil/Serializable/Serializable.h"

using namespace YanaPOnlineUtil::Packet;
using namespace YanaPOnlineUtil::Stream;

/**
 * @brief エネミーデータパケット
 */
class EnemyData : public YanaPOnlineUtil::Serializable::ISerializable
{

public:
	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	

	

	//! 座標
	PositionPack Position;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	EnemyData()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	EnemyData(PositionPack InPosition)
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

#endif // #ifndef __ENEMYDATA_H__
