#include "Peer/PeerBase.h"

using namespace YanaPServer::Socket;

namespace YanaPServer
{
namespace Peer
{

// �R���X�g���N�^
CPeerBase::CPeerBase(YanaPServer::Socket::ISocket *pSocket)
	: Socket(pSocket)
	, bDisconnect(false)
{
	Socket.SetEventListener(this);
}

// �f�X�g���N�^
CPeerBase::~CPeerBase()
{
	ReleaseSocket();
}

// ���t���[���̏���.
void CPeerBase::Poll()
{
	if (!IsValid()) { return; }

	Socket.Poll();

	if (bDisconnect)
	{
		ReleaseSocket();
	}
}

// �\�P�b�g�C�x���g���I�[�o�[���C�h����C�x���g���X�i���Z�b�g
void CPeerBase::SetOverrideEventListener(ISocketEventListener *pListener)
{
	Socket.SetEventListener(pListener);
}

// ���M.
void CPeerBase::Send(const char *pData, unsigned int Size)
{
	if (!IsValid()) { return; }

	Socket.Send(pData, Size);
}

// �ؒf.
void CPeerBase::Disconnect()
{
	// Socket��Poll�������ɐؒf�����\��������̂ŁA
	// ����̂͂����Ƀt���O�������ĂĂ����B
	// Poll������A�ؒf�t���O�������Ă���Ή�́B
	bDisconnect = true;
}


// �\�P�b�g���.
void CPeerBase::ReleaseSocket()
{
	Socket.Release(ESocketDisconnectReason::Destruct);
}

}
}
