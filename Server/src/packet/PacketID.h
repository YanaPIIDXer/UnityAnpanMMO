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
		//! エネミー出現パケット
		EnemyEntry = 0x01,
		//! LogInResultパケット
		LogInResult = 0x02,
		//! LogInRequestパケット
		LogInRequest = 0x03,
		//! Pingパケット
		Ping = 0x04,
		
	};
};

#endif		// #ifndef __PACKETID_H__
