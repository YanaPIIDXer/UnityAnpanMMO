/**
 * @file PacketLogInResult.h
 * @brief LogInResultパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETLOGINRESULT_H__
#define __PACKETLOGINRESULT_H__

#include "YanaPOnlineUtil/Packet/Packet.h"
#include "YanaPOnlineUtil/Stream/MemoryStream.h"
#include "type.h"
#include "PacketID.h"


using namespace YanaPOnlineUtil::Packet;
using namespace YanaPOnlineUtil::Stream;

/**
 * @brief LogInResultパケット
 */
class PacketLogInResult : public CPacket
{

public:
	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual unsigned char GetPacketId() const override { return PacketID::LogInResult; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! 不明なエラー
		Fatal,
	};

	//! リザルトコード
	byte Result;
	//! キャラクタID
	uint CharacterId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketLogInResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketLogInResult(byte InResult, uint InCharacterId)
	{
		Result = InResult;
		CharacterId = InCharacterId;
		
	}

	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(IMemoryStream *pStream)
	{
		if(!pStream->Serialize(&Result)) { return false; }
		if(!pStream->Serialize(&CharacterId)) { return false; }
		
		return true;
	}
};

#endif // #ifndef __PACKETLOGINRESULT_H__
