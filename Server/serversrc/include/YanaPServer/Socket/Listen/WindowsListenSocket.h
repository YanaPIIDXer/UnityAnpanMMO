#ifndef __WINDOWSLISTENSOCKET_H__
#define __WINDOWSLISTENSOCKET_H__

#ifdef _WIN32
#include <WinSock2.h>
#include "ListenSocket.h"

namespace YanaPServer
{
namespace Socket
{
class ISocket;

namespace Listen
{

/**
 * @class CWindowsListenSocket
 * @brief WindowsのListen用ソケットクラス
 */
class CWindowsListenSocket : public IListenSocket
{

public:

	/**
	 * @brief コンストラクタ
	 */
	CWindowsListenSocket();

	/**
	 * @brief デストラクタ
	 */
	virtual ~CWindowsListenSocket();

	/**
	 * @fn virtual void Poll() override
	 * @brief 毎フレーム呼び出す処理
	 */
	virtual void Poll() override;

	/**
	 * @fn virtual bool Init() override
	 * @brief ソケットの初期化
	 * @return 成功したらtrueを返す。
	 */
	virtual bool Init() override;

	/**
	 * @fn virtual bool Bind(unsigned int Port) override
	 * @brief バインド
	 * @param[in] Port ポート
	 * @return 成功したらtrueを返す。
	 */
	virtual bool Bind(unsigned int Port) override;

	/**
	 * @fn virtual bool Listen() override
	 * @brief リッスン開始
	 * @return 正常に開始したらtrueを返す。
	 */
	virtual bool Listen() override;

	/**
	 * @fn virtual void SetAcceptCallback(std::function<void(ISocket *)> &Callback) override
	 * @brief Accept時のコールバックを設定
	 * @param[in] Callback Accept時に呼び出されるコールバック
	 */
	virtual void SetAcceptCallback(const std::function<void(ISocket *)> &Callback) override { OnAccept = Callback; }

private:

	// ソケット
	SOCKET Socket;

	// ノンブロッキングモード
	u_long NonBlockingMode;

	// Accept時のコールバック
	std::function<void(ISocket *)> OnAccept;


	// 解放.
	void Release();

};

}
}
}

#endif		// #ifdef _WIN32


#endif			// #ifndef __WINDOWSLISTENSOCKET_H__
