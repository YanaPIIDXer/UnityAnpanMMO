#include "Socket/Socket.h"
#include "Socket/SocketEventListener.h"
#include "Socket/WidnowsSocket.h"
#include "Socket/LinuxSocket.h"
#include "Socket/NullSocket.h"
#include <memory.h>

namespace YanaPServer
{
namespace Socket
{

// �R���X�g���N�^
CSocket::CSocket()
	: pSocket(nullptr)
	, State(EState::None)
	, pEventListener(nullptr)
{
}

// �R���X�g���N�^
CSocket::CSocket(ISocket *pInSocket)
	: pSocket(pInSocket)
	, State(EState::Connected)
	, pEventListener(nullptr)
{
}

// �f�X�g���N�^
CSocket::~CSocket()
{
	Release(ESocketDisconnectReason::Destruct);
}

// ���t���[�����s���鏈��.
void CSocket::Poll()
{
	if (!IsValid()) { return; }

	switch (State)
	{
		case EState::Connecting:

			if (pSocket->PollConnect())
			{
				State = EState::Connected;
				if (pEventListener != nullptr)
				{
					pEventListener->OnConnect();
				}
			}
			break;

		case EState::Connected:

			SendProc();
			RecvProc();
			break;

		case EState::None:

			// �s�v�����ǁA�R�C�c��������Linux�ŃG���[�iWarning�j�ɂȂ�B
			break;
	}
}

// �ڑ�.
bool CSocket::Connect(const char *pHost, unsigned int Port)
{
	// �ڑ����������ꍇ�͐ؒf�B
	if (IsValid())
	{
		Release(ESocketDisconnectReason::Destruct);
	}

#ifdef _WIN32
	pSocket = new CWindowsSocket();
#elif defined _LINUX
	pSocket = new CLinuxSocket();
#else
	pSocket = new CNullSocket();
#endif
	
	if (!pSocket->Connect(pHost, Port)) { return false; }

	State = EState::Connecting;

	return true;
}

// ���M.
bool CSocket::Send(const char *pData, unsigned int Size)
{
	if (!IsValid()) { return false; }

	for (unsigned int i = 0; i < Size; i++)
	{
		DataQueue.push_back(pData[i]);
	}

	return true;
}

// ���.
void CSocket::Release(ESocketDisconnectReason Reason)
{
	if (pSocket == nullptr) { return; }

	delete pSocket;
	pSocket = nullptr;

	State = EState::None;

	if (pEventListener != nullptr)
	{
		pEventListener->OnDisconnect(Reason);
	}
}


// ���M����.
void CSocket::SendProc()
{
	if (!IsValid() || DataQueue.size() == 0) { return; }

	int SendSize = pSocket->Send(&DataQueue[0], DataQueue.size());

	if (SendSize == -1)
	{
		Release(ESocketDisconnectReason::SendError);
		return;
	}

	for (int i = 0; i < SendSize; i++)
	{
		DataQueue.erase(DataQueue.begin());
	}

	if (SendSize > 0 && pEventListener != nullptr)
	{
		pEventListener->OnSend(SendSize);
	}
}

// ��M����.
void CSocket::RecvProc()
{
	if (!IsValid()) { return; }

	// �C�x���g���X�i���ݒ肳��Ă��Ȃ��ꍇ�͉������Ȃ��B
	if (pEventListener == nullptr) { return; }

	static const int BufferSize = 2048;
	char Buffer[BufferSize];
	memset(Buffer, 0, BufferSize);

	int RecvSize = pSocket->Recv(Buffer, BufferSize);
	if (RecvSize == -1)
	{
		Release(ESocketDisconnectReason::RecvError);
		return;
	}

	if (RecvSize > 0)
	{
		pEventListener->OnRecv(Buffer, RecvSize);
	}
}

}
}
