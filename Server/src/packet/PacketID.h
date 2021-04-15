/**
 * @file $FILE_NAME$
 * @brief �p�P�b�g�h�c��`.
 * @author NativePacketGenerator
 */

#ifndef __PACKETID_H__
#define __PACKETID_H__

/**
 * @brief �p�P�b�g�h�c��`.
 */
class PacketID
{

public:

	/**
	 * @enum EID
	 * �p�P�b�g�h�c
	 */
	enum EID
	{
		//! エリア切り替え要求パケット
		AreaChange = 0x01,
		//! エリア切り替え完了パケット
		AreaLoadEnd = 0x02,
		//! エネミーリストパケット
		EnemyList = 0x03,
		//! エネミー出現パケット
		EnemyEntry = 0x04,
		//! LogInResultパケット
		LogInResult = 0x05,
		//! LogInRequestパケット
		LogInRequest = 0x06,
		//! Pingパケット
		Ping = 0x07,
		
	};
};

#endif		// #ifndef __PACKETID_H__
