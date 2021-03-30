#include "Socket/LinuxSocket.h"

#ifdef _LINUX

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define SOCKET_ERROR -1

namespace YanaPServer
{
namespace Socket
{

// コンストラクタ
CLinuxSocket::CLinuxSocket()
	: Socket(INVALID_SOCKET)
	, NonBlockingMode(1)
{
}

// コンストラクタ
CLinuxSocket::CLinuxSocket(int InSocket)
	: Socket(InSocket)
	, NonBlockingMode(1)
{
	ioctl(Socket, FIONBIO, &NonBlockingMode);
}

// デストラクタ
CLinuxSocket::~CLinuxSocket()
{
	if (Socket == INVALID_SOCKET) { return; }
	close(Socket);
}

// 接続.
bool CLinuxSocket::Connect(const char *pHost, unsigned int Port)
{
	Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (Socket == INVALID_SOCKET) { return false; }

	ConnectAddr.sin_family = AF_INET;
	ConnectAddr.sin_port = htons(Port);
	ConnectAddr.sin_addr.s_addr = inet_addr(pHost);

	ioctl(Socket, FIONBIO, &NonBlockingMode);

	return true;
}

// 接続されるまで毎フレーム実行される処理
bool CLinuxSocket::PollConnect()
{
	return (connect(Socket, (sockaddr *)&ConnectAddr, sizeof(ConnectAddr)) != 0);
}

// 送信.
int CLinuxSocket::Send(const char *pData, unsigned int Size)
{
	int SendSize = write(Socket, pData, Size);
	if (SendSize == SOCKET_ERROR) { return -1; }
	return SendSize;
}

// 受信.
int CLinuxSocket::Recv(char *pBuffer, unsigned int BufferSize)
{
	int RecvSize = read(Socket, pBuffer, BufferSize);
	if (RecvSize == SOCKET_ERROR)
	{
		// ↓まだ受信していない場合は以下のエラーが吐き出される。
		if (errno != EAGAIN && errno != EWOULDBLOCK) { return -1; }
		return 0;
	}

	return RecvSize;
}

}
}

#endif		// #ifdef _LINUX
