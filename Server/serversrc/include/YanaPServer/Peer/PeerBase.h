#ifndef __PEERBASE_H__
#define __PEERBASE_H__

#include "../Socket/Socket.h"
#include "../Socket/SocketEventListener.h"

namespace YanaPServer
{
namespace Peer
{

/**
 * @class CPeerBase
 * @brief ピア基底クラス
 * @detail 基本的にはコイツを派生したクラスのweak_ptrを利用者側で管理する。
 *	       切断時には勝手に消失する（親になるshared_ptrが消える）ので、
 *	       コイツを使って何かやる時はexpired()チェックしないと死なますよ。
 */
class CPeerBase : public YanaPServer::Socket::ISocketEventListener
{

public:
	
	/**
	 * @brief コンストラクタ
	 * @param[in] pSocket ソケット
	 */
	CPeerBase(YanaPServer::Socket::ISocket *pSocket);

	/**
	 * @brief デストラクタ
	 */
	virtual ~CPeerBase() = 0;

	/**
	 * @fn void Poll()
	 * @brief 毎フレームの処理
	 */
	void Poll();

	/**
	 * @fn void SetOverrideEventListener(ISocketEventListener *pListener)
	 * @brief ソケットイベントをオーバーライドするイベントリスナをセット
	 * @detail イベントリスナのメモリ管理（delete等）は行わないので注意。
	 * @param[in] pListener イベントリスナ
	 */
	void SetOverrideEventListener(ISocketEventListener *pListener);

	/**
	 * @fn void RemoveOverrideEventListener()
	 * @brief ソケットイベントをオーバーライドするイベントリスナを解除。
	 */
	void RemoveOverrideEventListener() { SetOverrideEventListener(this); }

	/**
	 * @fn bool IsValid() const
	 * @brief 有効か？
	 * @return 有効ならtrueを返す。
	 */
	bool IsValid() const { return (Socket.IsValid()); }

	/**
	 * @fn void Send(const char *pData, unsigned int Size)
	 * @brief 送信
	 * @param[in] pData データ
	 * @param[in] Size データ長
	 */
	void Send(const char *pData, unsigned int Size);

	/**
	 * @fn void Disconnect()
	 * @brief 切断
	 */
	void Disconnect();

	/**
	 * @fn virtual void OnConnect() override
	 * @brief 接続された
	 */
	virtual void OnConnect() override {}

	/**
	 * @fn virtual void OnSend(unsigned int Size) override
	 * @brief 送信した
	 * @param[in] Size 送信したデータ長
	 */
	virtual void OnSend(unsigned int Size) override {}

	/**
	 * @fn virtual void OnDisconnect(YanaPServer::Socket::ESocketDisconnectReason Reason) override
	 * @brief 切断された
	 * @paran[in] Reason 切断理由
	 */
	virtual void OnDisconnect(YanaPServer::Socket::ESocketDisconnectReason Reason) override {}

private:

	// ソケット
	YanaPServer::Socket::CSocket Socket;

	// 切断フラグ
	bool bDisconnect;


	// ソケット解放.
	void ReleaseSocket();

};

}
}

#endif		// #ifndef __PEERBASE_H__
