#ifndef __NULLLISTENSOCKET_H__
#define __NULLLISTENSOCKET_H__

#include "ListenSocket.h"

namespace YanaPServer
{
namespace Socket
{
class ISocket;

namespace Listen
{

/**
 * @class CNullListenSocket
 * @brief 何もしないListenSocketクラス
 *		  未定義のプラットフォームで使用する。
 */
class CNullListenSocket : public IListenSocket
{

public:

	/**
	 * @brief コンストラクタ
	 */
	CNullListenSocket() {}

	/**
	 * @brief デストラクタ
	 */
	virtual ~CNullListenSocket() {}

	/**
	 * @fn virtual void Poll() override
	 * @brief 毎フレーム呼び出す処理
	 */
	virtual void Poll() override {}

	/**
	 * @fn virtual bool Init() override
	 * @brief ソケットの初期化
	 * @return 何もしないので常にfalseを返す。
	 */
	virtual bool Init() override { return false; }

	/**
	 * @fn virtual bool Bind(unsigned int Port) override
	 * @brief バインド
	 * @param[in] Port ポート
	 * @return 何もしないので常にfalseを返す。
	 */
	virtual bool Bind(unsigned int Port) override { return false; }

	/**
	 * @fn virtual bool Listen() override
	 * @brief リッスン開始
	 * @return 何もしないので常にfalseを返す。
	 */
	virtual bool Listen() override { return false; }

	/**
	 * @fn virtual void SetAcceptCallback(std::function<void(ISocket *)> &Callback) override
	 * @brief Accept時のコールバックを設定
	 * @param[in] Callback Accept時に呼び出されるコールバック
	 */
	virtual void SetAcceptCallback(const std::function<void(ISocket *)> &Callback) override {}

};

}
}
}

#endif		// #ifndef __NULLLISTENSOCKET_H__
