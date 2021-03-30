#include "Socket/Listen/LinuxListenSocket.h"

#ifdef _LINUX

#include "Socket/LinuxSocket.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

namespace YanaPServer
{
namespace Socket
{
namespace Listen
{

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

// �R���X�g���N�^
CLinuxListenSocket::CLinuxListenSocket()
	: Socket(INVALID_SOCKET)
	, NonBlockingMode(1)
{
}

// �f�X�g���N�^
CLinuxListenSocket::~CLinuxListenSocket()
{
	Release();
}

// ���t���[���Ăт�������.
void CLinuxListenSocket::Poll()
{
	if (Socket == INVALID_SOCKET) { return; }

	sockaddr_in Addr;
	socklen_t Len = sizeof(Addr);
	int AcceptSocket = accept(Socket, (sockaddr *)&Addr, &Len);
	if (AcceptSocket == INVALID_SOCKET) { return; }

	CLinuxSocket *pNewSocket = new CLinuxSocket(AcceptSocket);
	OnAccept(pNewSocket);
}

// �\�P�b�g�̏�����.
bool CLinuxListenSocket::Init()
{
	// ���ɐ�������Ă���Ȃ��U��́B
	if (Socket != INVALID_SOCKET)
	{
		Release();
	}

	Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (Socket == INVALID_SOCKET) { return false; }

	ioctl(Socket, FIONBIO, &NonBlockingMode);

	return true;
}

// �o�C���h
bool CLinuxListenSocket::Bind(unsigned int Port)
{
	if (Socket == INVALID_SOCKET) { return false; }

	sockaddr_in Addr;

	Addr.sin_family = AF_INET;
	Addr.sin_port = htons(Port);
	Addr.sin_addr.s_addr = INADDR_ANY;

	return (bind(Socket, (sockaddr *)&Addr, sizeof(Addr)) != SOCKET_ERROR);
}

// ���b�X��
bool CLinuxListenSocket::Listen()
{
	if (Socket == INVALID_SOCKET) { return false; }

	return (listen(Socket, 1) != SOCKET_ERROR);
}

// ���.
void CLinuxListenSocket::Release()
{
	if (Socket == INVALID_SOCKET) { return; }

	close(Socket);
	Socket = INVALID_SOCKET;
}

}
}
}

#endif		// #ifdef _LINUX
