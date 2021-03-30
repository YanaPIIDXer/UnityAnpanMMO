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

// �R���X�g���N�^
CLinuxSocket::CLinuxSocket()
	: Socket(INVALID_SOCKET)
	, NonBlockingMode(1)
{
}

// �R���X�g���N�^
CLinuxSocket::CLinuxSocket(int InSocket)
	: Socket(InSocket)
	, NonBlockingMode(1)
{
	ioctl(Socket, FIONBIO, &NonBlockingMode);
}

// �f�X�g���N�^
CLinuxSocket::~CLinuxSocket()
{
	if (Socket == INVALID_SOCKET) { return; }
	close(Socket);
}

// �ڑ�.
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

// �ڑ������܂Ŗ��t���[�����s����鏈��
bool CLinuxSocket::PollConnect()
{
	return (connect(Socket, (sockaddr *)&ConnectAddr, sizeof(ConnectAddr)) != 0);
}

// ���M.
int CLinuxSocket::Send(const char *pData, unsigned int Size)
{
	int SendSize = write(Socket, pData, Size);
	if (SendSize == SOCKET_ERROR) { return -1; }
	return SendSize;
}

// ��M.
int CLinuxSocket::Recv(char *pBuffer, unsigned int BufferSize)
{
	int RecvSize = read(Socket, pBuffer, BufferSize);
	if (RecvSize == SOCKET_ERROR)
	{
		// ���܂���M���Ă��Ȃ��ꍇ�͈ȉ��̃G���[���f���o�����B
		if (errno != EAGAIN && errno != EWOULDBLOCK) { return -1; }
		return 0;
	}

	return RecvSize;
}

}
}

#endif		// #ifdef _LINUX
