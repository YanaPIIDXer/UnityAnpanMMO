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
		//! LogInResultパケット
		LogInResult = 0x01,
		//! LogInRequestパケット
		LogInRequest = 0x02,
		//! Pingパケット
		Ping = 0x03,
		
	};
};

#endif		// #ifndef __PACKETID_H__
