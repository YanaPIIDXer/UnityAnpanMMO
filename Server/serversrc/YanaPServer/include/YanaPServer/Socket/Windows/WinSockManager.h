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
 * @brief WinSock�̊Ǘ�.
 * @detail �V���O���g���N���X
 */
class CWinSockManager
{

public:

	/**
	 * @brief �f�X�g���N�^
	 */
	~CWinSockManager();

	/**
	 * @fn bool Initialize()
	 * @brief ������
	 * @return ����������true��Ԃ��B
	 */
	bool Initialize();

private:

	// ����������Ă��邩�H
	bool bInitialized;

	// ============ Singleton ==============
public:

	/**
	 * @fn static CWinSockManager &GetInstance()
	 * @brief �V���O���g���C���X�^���X�擾
	 * @return �V���O���g���C���X�^���X
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
