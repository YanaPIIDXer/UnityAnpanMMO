#ifndef __WINDOWSSOCKETBEHAVIOUR_H__
#define __WINDOWSSOCKETBEHAVIOUR_H__

#ifdef _WIN32

#include "Socket.h"
#include <WinSock2.h>

namespace YanaPServer
{
namespace Socket
{

/**
 * @class CWindowsSocket
 * @brief Windowsでのソケットの挙動を実装するクラス
 */
class CWindowsSocket : public ISocket
{

public:

	/**
	 * @brief コンストラクタ
	 */
	CWindowsSocket();

	/**
	 * @brief コンストラクタ
	 * @param[in] InSocket ソケット
	 */
	CWindowsSocket(const SOCKET &InSocket);

	/**
	 * @brief デストラクタ
	 */
	virtual ~CWindowsSocket();

	/**
	 * @fn virtual bool Connect(const char *pHost, unsigned int Port) override
	 * @brief 接続
	 * @param[in] pHost ホスト
	 * @param[in] Port ポート
	 * @return 成功したらtrueを返す。
	 */
	virtual bool Connect(const char *pHost, unsigned int Port) override;

	/**
	 * @fn virtual bool PollConnect() override
	 * @brief 接続されるまで毎フレーム実行される処理
	 * @return 接続に成功したらtrueを返す。
	 */
	virtual bool PollConnect() override;

	/**
	 * @fn virtual bool IsValid() const override
	 * @brief 有効か？
	 * @return 有効ならtrueを返す。
	 */
	virtual bool IsValid() const override { return (Socket != INVALID_SOCKET); }

	/**
	 * @fn virtual bool Send(const char *pData, unsigned int Size) override
	 * @brief 送信
	 * @param[in] pData データ
	 * @param[in] Size 送信サイズ
	 * @return 送信バイト数を返す。失敗時は-1を返す。
	 */
	virtual int Send(const char *pData, unsigned int Size) override;

	/**
	 * @fn virtual int Recv(char *pBuffer, unsigned int BufferSize) override
	 * @brief 受信
	 * @param[in] pBuffer バッファ
	 * @param[in] BufferSize バッファサイズ
	 * @return 受信バイト数を返す。失敗時は-1を返す。
	 */
	virtual int Recv(char *pBuffer, unsigned int BufferSize) override;

private:

	// ソケット
	SOCKET Socket;

	// ノンブロッキングモード
	u_long NonBlockingMode;

	// 接続先アドレス
	sockaddr_in ConnectAddr;

};

}
}

#endif		// #ifdef _WIN32

#endif		// #ifndef __WINDOWSSOCKETBEHAVIOUR_H__
