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
		//! エネミーリストパケット
		EnemyList = 0x01,
		//! エネミー出現パケット
		EnemyEntry = 0x02,
		//! LogInResultパケット
		LogInResult = 0x03,
		//! LogInRequestパケット
		LogInRequest = 0x04,
		//! Pingパケット
		Ping = 0x05,
		
	};
};

#endif		// #ifndef __PACKETID_H__
