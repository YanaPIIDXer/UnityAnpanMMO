#ifndef __PACKETSERIALIZER_H__
#define __PACKETSERIALIZER_H__

#include <functional>
#include "../Stream/MemoryStream.h"
#include <vector>

namespace YanaPOnlineUtil
{
namespace Packet
{

class CPacket;

/**
 * @class CPacketSerializer
 * @brief パケットシリアライズクラス
 */
class CPacketSerializer
{

private:		// 別名定義.

	typedef std::function<void(unsigned char, Stream::IMemoryStream *)> RecvFunction;
	typedef std::function<void(const char *, unsigned int)> SendFunction;

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] InRecvFunc 受信関数
	 * @param[in] InSendFunc 送信関数
	 */
	CPacketSerializer(const RecvFunction &InRecvFunc, const SendFunction &InSendFunc);

	/**
	 * @brief デストラクタ
	 */
	~CPacketSerializer();

	/**
	 * @fn void OnRecv(const char *pData, unsigned int Size)
	 * @brief 受信した
	 * @param[in] pData データ
	 * @param[in] Size データサイズ
	 */
	void OnRecv(const char *pData, unsigned int Size);

	/**
	 * @fn void Send(CPacket *pPacket)
	 * @brief 送信
	 * @param[in] 送信パケット
	 */
	void Send(CPacket *pPacket);
		
private:

	// 受信関数.
	 RecvFunction RecvFunc;

	// 送信関数.
	 SendFunction SendFunc;

	 // バッファ
	 std::vector<char> Buffer;
};

}
}

#endif		// #ifndef __PACKETSERIALIZER_H__
