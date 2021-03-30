#ifndef __WINSOCKMANAGER_H__
#define __WINSOCKMANAGER_H__

#if _WIN32

namespace YanaPServer
{
namespace Socket
{
namespace Windows
{

/**
 * @class CWinSockManager
 * @brief WinSockの管理.
 * @detail シングルトンクラス
 */
class CWinSockManager
{

public:

	/**
	 * @brief デストラクタ
	 */
	~CWinSockManager();

	/**
	 * @fn bool Initialize()
	 * @brief 初期化
	 * @return 成功したらtrueを返す。
	 */
	bool Initialize();

private:

	// 初期化されているか？
	bool bInitialized;

	// ============ Singleton ==============
public:

	/**
	 * @fn static CWinSockManager &GetInstance()
	 * @brief シングルトンインスタンス取得
	 * @return シングルトンインスタンス
	 */
	static CWinSockManager &GetInstance() { return Instance; }

private:

	CWinSockManager();
	static CWinSockManager Instance;

};

}
}
}

#endif			// #if _WIN32

#endif			// #ifndef __WINSOCKMANAGER_H__
