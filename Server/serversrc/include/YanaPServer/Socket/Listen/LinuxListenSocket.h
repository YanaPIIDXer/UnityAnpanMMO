#ifndef __LINUXLISTENSOCKET_H__
#define __LINUXLISTENSOCKET_H__

#ifdef _LINUX

#include "ListenSocket.h"

namespace YanaPServer
{
namespace Socket
{
namespace Listen
{

/**
 * @class CLinuxListenSocket
 * @brief Linux用Listenソケット
 */
class CLinuxListenSocket : public IListenSocket
{

public:

	/**
	 * @brief コンストラクタ
	 */
	CLinuxListenSocket();

	/**
	 * @brief デストラクタ
	 */
	virtual ~CLinuxListenSocket();

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
	int Socket;

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

#endif		// #ifdef _LINUX

#endif		// #ifndef __LINUXLISTENSOCKET_H__
