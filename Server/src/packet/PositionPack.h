/**
 * @file PositionPack.h
 * @brief PositionPackパケット
 * @author NativePacketGenerator
 */

#ifndef __POSITIONPACK_H__
#define __POSITIONPACK_H__

#include "YanaPOnlineUtil/Packet/Packet.h"
#include "YanaPOnlineUtil/Stream/MemoryStream.h"
#include "type.h"
#include "YanaPOnlineUtil/Serializable/Serializable.h"

using namespace YanaPOnlineUtil::Packet;
using namespace YanaPOnlineUtil::Stream;

/**
 * @brief PositionPackパケット
 */
class PositionPack : public YanaPOnlineUtil::Serializable::ISerializable
{

public:
	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	

	

	//! X座標
	float X;
	//! Y座標
	float Y;
	//! Z座標
	float Z;
	//! 回転
	float Rotation;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PositionPack()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PositionPack(float InX, float InY, float InZ, float InRotation)
	{
		X = InX;
		Y = InY;
		Z = InZ;
		Rotation = InRotation;
		
	}

	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(IMemoryStream *pStream)
	{
		if(!pStream->Serialize(&X)) { return false; }
		if(!pStream->Serialize(&Y)) { return false; }
		if(!pStream->Serialize(&Z)) { return false; }
		if(!pStream->Serialize(&Rotation)) { return false; }
		
		return true;
	}
};

#endif // #ifndef __POSITIONPACK_H__
