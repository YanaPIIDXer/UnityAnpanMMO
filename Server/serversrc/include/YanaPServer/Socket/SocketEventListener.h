#ifndef __SOCKETEVENTLISTENER_H__
#define __SOCKETEVENTLISTENER_H__

namespace YanaPServer
{
namespace Socket
{

/**
 * @class ISocketEventListener
 * @brief ソケットイベントリスナ
 */
class ISocketEventListener
{
public:

	/**
	 * @brief デストラクタ
	 */
	virtual ~ISocketEventListener() {}

	/**
	 * @fn virtual void OnConnect() = 0
	 * @brief 接続された
	 */
	virtual void OnConnect() = 0;

	/**
	 * @fn virtual void OnRecv(const char *pData, unsigned int Size) = 0
	 * @brief 受信した
	 * @param[in] pData データ
	 * @param[in] Size データ長
	 */
	virtual void OnRecv(const char *pData, unsigned int Size) = 0;

	/**
	 * @fn virtual void OnSend(unsigned int Size) = 0
	 * @brief 送信した
	 * @param[in] Size 送信したデータ長
	 */
	virtual void OnSend(unsigned int Size) = 0;

	/**
	 * @fn virtual void OnDisconnect(ESocketDisconnectReason Reason) = 0
	 * @brief 切断された
	 * @param[in] Reason 切断理由
	 */
	virtual void OnDisconnect(ESocketDisconnectReason Reason) = 0;

};

}
}
#endif		// #ifndef __SOCKETEVENTLISTENER_H__
