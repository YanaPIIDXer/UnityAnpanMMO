#ifndef __NULLSOCKETBEHAVIOUR_H__
#define __NULLSOCKETBEHAVIOUR_H__

#include "Socket.h"

namespace YanaPServer
{
namespace Socket
{

/**
 * @class CNullSocket
 * @brief 何もしないSocket
 *		  未定義のプラットフォームで使用される。
 */
class CNullSocket : public ISocket
{

public:

	/**
	 * @brief コンストラクタ
	 */
	CNullSocket() {}

	/**
	 * @brief デストラクタ
	 */
	virtual ~CNullSocket() {}

	/**
	 * @fn virtual boool PollConnect() override
	 * @brief 接続されるまで毎フレーム実行される処理
	 * @return 何もしないので常にfalseを返す。
	 */
	virtual bool PollConnect() override { return false; }

	/**
	 * @fn virtual bool Connect(const char *pHost, unsigned int Port) override
	 * @brief 接続
	 * @param[in] pHost ホスト
	 * @param[in] Port ポート
	 * @return 何もしないので常にfalseを返す。
	 */
	virtual bool Connect(const char *pHost, unsigned int Port) override { return false; }

	/**
	 * @fn virtual bool IsValid() const override
	 * @brief 有効か？
	 * @return 有効にはならないので常にfalseを返す。
	 */
	virtual bool IsValid() const override { return false; }

	/**
	 * @fn virtual bool Send(const char *pData, unsigned int Size) override
	 * @brief 送信
	 * @param[in] pData データ
	 * @param[in] Size 送信サイズ
	 * @return 何もしないので常に-1を返す。
	 */
	virtual int Send(const char *pData, unsigned int Size) override { return false; }

	/**
	 * @fn virtual int Recv(char *pBuffer, unsigned int BufferSize) override
	 * @brief 受信
	 * @param[in] pBuffer バッファ
	 * @param[in] BufferSize バッファサイズ
	 * @return 何もしないので常に-1を返す。
	 */
	virtual int Recv(char * pBuffer, unsigned int BufferSize) override { return -1; }

};

}
}

#endif		// #ifndef __NULLSOCKETBEHAVIOUR_H__
