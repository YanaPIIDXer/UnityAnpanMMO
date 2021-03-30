#ifdef _WIN32
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Socket/WidnowsSocket.h"
#include "Socket/Windows/WinSockManager.h"

namespace YanaPServer
{
namespace Socket
{

// コンストラクタ
CWindowsSocket::CWindowsSocket()
	: Socket(INVALID_SOCKET)
	, NonBlockingMode(1)
{
}

// コンストラクタ
CWindowsSocket::CWindowsSocket(const SOCKET &InSocket)
	: Socket(InSocket)
	, NonBlockingMode(1)
{
	ioctlsocket(Socket, FIONBIO, &NonBlockingMode);
}

// デストラクタ
CWindowsSocket::~CWindowsSocket()
{
	if (Socket == INVALID_SOCKET) { return; }
	closesocket(Socket);
}

// 接続.
bool CWindowsSocket::Connect(const char *pHost, unsigned int Port)
{
	if (!Windows::CWinSockManager::GetInstance().Initialize()) { return false; }

	Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (Socket == INVALID_SOCKET) { return false; }

	ConnectAddr.sin_family = AF_INET;
	ConnectAddr.sin_port = htons(Port);
	ConnectAddr.sin_addr.S_un.S_addr = inet_addr(pHost);

	ioctlsocket(Socket, FIONBIO, &NonBlockingMode);

	return true;
}

// 接続されるまで毎フレーム実行される処理.
bool CWindowsSocket::PollConnect()
{
	return (connect(Socket, (sockaddr *)&ConnectAddr, sizeof(ConnectAddr)) == 0);
}

// 送信.
int CWindowsSocket::Send(const char *pData, unsigned int Size)
{
	if (Socket == INVALID_SOCKET) { return false; }

	int SendSize = send(Socket, pData, Size, 0);
	if (SendSize == SOCKET_ERROR) { return -1; }
	return SendSize;
}

// 受信.
int CWindowsSocket::Recv(char *pBuffer, unsigned int BufferSize)
{
	int RecvSize = recv(Socket, pBuffer, BufferSize, 0);
	if (RecvSize == SOCKET_ERROR)
	{
		// ↓まだ受信していない場合は以下のエラーが吐き出される。
		if (WSAGetLastError() != WSAEWOULDBLOCK) { return -1; }
		return 0;
	}

	return RecvSize;
}

}
}

#endif		// #ifdef _WIN32
