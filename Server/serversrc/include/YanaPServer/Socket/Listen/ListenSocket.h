#ifndef __LISTENSOCKET_H__
#define __LISTENSOCKET_H__

#include <functional>
#include <memory>

namespace YanaPServer
{
namespace Socket
{
class ISocket;

namespace Listen
{

/**
 * @class IListenSocket
 * @brief Listen用Socketインタフェース
 */
class IListenSocket
{

public:

	/**
	 * @brief デストラクタ
	 */
	virtual ~IListenSocket() {}

	/**
	 * @fn virtual void Poll() = 0;
	 * @brief 毎フレーム呼び出す処理
	 */
	virtual void Poll() = 0;

	/**
	 * @fn virtual bool Init() = 0
	 * @brief ソケットの初期化
	 * @return 成功したらtrueを返す。
	 */
	virtual bool Init() = 0;

	/**
	 * @fn virtual bool Bind(unsigned int Port) = 0
	 * @brief バインド
	 * @param[in] Port ポート
	 * @return 成功したらtrueを返す。
	 */
	virtual bool Bind(unsigned int Port) = 0;

	/**
	 * @fn virtual bool Listen() = 0
	 * @brief リッスン開始
	 * @return 正常に開始したらtrueを返す。
	 */
	virtual bool Listen() = 0;

	/**
	 * @fn virtual void SetAcceptCallback(const std::function<void(ISocket *)> &Callback) = 0
	 * @brief Accept時のコールバックを設定
	 * @param[in] Callback Accept時に呼び出されるコールバック
	 */
	virtual void SetAcceptCallback(const std::function<void(ISocket *)> &Callback) = 0;

};

typedef std::unique_ptr<IListenSocket> ListenSocketPtr;

/**
 * @class CListenSocket
 * @brief Listen用Socketクラス
 */
class CListenSocket
{

public:

	/**
	 * @fn static void Build(unsigned int Port, std::function<void(ISocket *)> &AcceptCallback)
	 * @brief 構築
	 * @param[in] Port ポート
	 * @param[in] AcceptCallback Accept時のコールバック
	 * @return 成功したらtrueを返す。
	 */
	static ListenSocketPtr Build(unsigned int Port, const std::function<void(ISocket *)> &AcceptCallback);

private:

	// ListenSocketオブジェクトを生成。
	static ListenSocketPtr Create();
	
};

}
}
}

#endif		// #ifndef __LISTENSOCKET_H__
