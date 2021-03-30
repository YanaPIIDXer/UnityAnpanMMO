#ifndef __SOCKETBEHAVIOUR_H__
#define __SOCKETBEHAVIOUR_H__

#include <functional>
#include <vector>

namespace YanaPServer
{
namespace Socket
{

class ISocketEventListener;

/**
 * @enum ESocketDisconnectReason
 * @brief ソケット切断理由
 */
enum class ESocketDisconnectReason
{
	//! デストラクタ等
	Destruct,

	//! 送信エラー
	SendError,

	//! 受信エラー
	RecvError,
};

/**
 * @class ISocket
 * @brief ソケットの挙動を実装するためのインタフェース
 */
class ISocket
{

public:

	/**
	 * @brief デストラクタ
	 */
	virtual ~ISocket() {}

	/**
	 * @fn virtual bool Connect(const char *pHost, unsigned int Port) = 0
	 * @brief 接続
	 * @param[in] pHost ホスト
	 * @param[in] Port ポート
	 * @return 成功したらtrueを返す。
	 */
	virtual bool Connect(const char *pHost, unsigned int Port) = 0;

	/**
	 * @fn virtual boool PollConnect() = 0
	 * @brief 接続されるまで毎フレーム実行される処理
	 * @return 接続に成功したらtrueを返す。
	 */
	virtual bool PollConnect() = 0;

	/**
	 * @fn virtual bool IsValid()
	 * @brief 有効か？
	 * @return 有効ならtrueを返す。
	 */
	virtual bool IsValid() const = 0;

	/**
	 * @fn virtual bool Send(const char *pData, unsigned int Size) = 0
	 * @brief 送信
	 * @param[in] pData データ
	 * @param[in] Size 送信サイズ
	 * @return 送信バイト数を返す。失敗時は-1を返す。
	 */
	virtual int Send(const char *pData, unsigned int Size) = 0;

	/**
	 * @fn virtual int Recv(char *pBuffer, unsigned int BufferSize) = 0
	 * @brief 受信
	 * @param[in] pBuffer バッファ
	 * @param[in] BufferSize バッファサイズ
	 * @return 受信バイト数を返す。失敗時は-1を返す。
	 */
	virtual int Recv(char *pBuffer, unsigned int BufferSize) = 0;

};

/**
 * @class CSocket
 * @brief ソケットクラス
 *        各プラットフォームで共通する部分。
 */
class CSocket
{

public:

	/**
	 * @brief コンストラクタ
	 */
	CSocket();

	/**
	 * @brief コンストラクタ
	 * @param[in] pInSocket ソケット
	 */
	CSocket(ISocket *pInSocket);

	/**
	 * @brief デストラクタ
	 */
	~CSocket();

	/**
	 * @fn void SetEventListener()
	 * @brief イベントリスナをセット
	 * @param[in] pListener イベントリスナ
	 */
	void SetEventListener(ISocketEventListener *pListener) { pEventListener = pListener; }

	/**
	 * @fn void Poll()
	 * @brief 毎フレーム実行する処理
	 */
	void Poll();

	/**
	 * @fn bool Connect(const char *pHost, unsigned int Port)
	 * @brief 接続
	 * @param[in] pHost ホスト
	 * @param[in] Port ポート
	 * @return 成功したらtrueを返す。
	 */
	bool Connect(const char *pHost, unsigned int Port);

	/**
	 * @fn bool IsValid() const
	 * @brief 有効か？
	 * @return 有効ならtrueを返す。
	 */
	bool IsValid() const { return (pSocket != nullptr && pSocket->IsValid()); }

	/**
	 * @fn virtual bool Send(const char *pData, unsigned int Size) = 0
	 * @brief 送信
	 * @param[in] pData データ
	 * @param[in] Size 送信サイズ
	 * @return 成功したらtrueを返す。
	 */
	bool Send(const char *pData, unsigned int Size);

	/**
	 * @fn void Release(ESocketDisconnectReason Reason)
	 * @brief 解放
	 * @param[in] Reason 切断理由
	 */
	void Release(ESocketDisconnectReason Reason);

private:

	// State
	enum class EState
	{
		// 何もしていない
		None,

		// 接続中.
		Connecting,

		// 接続した
		Connected,
	};

	// ソケット
	ISocket *pSocket;

	// ステート
	EState State;

	// データキュー
	std::vector<char> DataQueue;

	// イベントリスナ
	ISocketEventListener *pEventListener;


	// 送信処理.
	void SendProc();

	// 受信処理.
	void RecvProc();

};

}
}

#endif		// #ifndef __SOCKETBEHAVIOUR_H__
