#if _WIN32
#include "Socket/Windows/WinSockManager.h"
#include <WinSock2.h>

namespace YanaPServer
{
namespace Socket
{
namespace Windows
{

CWinSockManager CWinSockManager::Instance;

// �R���X�g���N�^
CWinSockManager::CWinSockManager()
	: bInitialized(false)
{
}

// �f�X�g���N�^
CWinSockManager::~CWinSockManager()
{
	if (!bInitialized) { return; }

	WSACleanup();
	bInitialized = false;
}

// ������.
bool CWinSockManager::Initialize()
{
	if (bInitialized) { return true; }

	WSADATA WsaData;
	int Result = WSAStartup(MAKEWORD(2, 0), &WsaData);
	if (Result != 0) { return false; }

	bInitialized = true;
	return true;
}

}
}
}

#endif		// #if _WIN32
