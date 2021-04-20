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
		//! プレイヤー位置変更パケット
		PlayerPositionChange = 0x03,
		//! エネミーリストパケット
		EnemyList = 0x04,
		//! エネミー出現パケット
		EnemyEntry = 0x05,
		//! LogInResultパケット
		LogInResult = 0x06,
		//! LogInRequestパケット
		LogInRequest = 0x07,
		//! Pingパケット
		Ping = 0x08,
		//! プレイヤーリストパケット
		PlayerList = 0x09,
		//! プレイヤー出現パケット
		PlayerEntry = 0x0A,
		//! プレイヤー移動パケット
		PlayerMove = 0x0B,
		//! プレイヤーが移動したパケット
		PlayerMoved = 0x0C,
		
	};
};

#endif		// #ifndef __PACKETID_H__
