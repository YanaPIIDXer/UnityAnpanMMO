#include "Peer/PeerBase.h"

using namespace YanaPServer::Socket;

namespace YanaPServer
{
namespace Peer
{

// コンストラクタ
CPeerBase::CPeerBase(YanaPServer::Socket::ISocket *pSocket)
	: Socket(pSocket)
	, bDisconnect(false)
{
	Socket.SetEventListener(this);
}

// デストラクタ
CPeerBase::~CPeerBase()
{
	ReleaseSocket();
}

// 毎フレームの処理.
void CPeerBase::Poll()
{
	if (!IsValid()) { return; }

	Socket.Poll();

	if (bDisconnect)
	{
		ReleaseSocket();
	}
}

// ソケットイベントをオーバーライドするイベントリスナをセット
void CPeerBase::SetOverrideEventListener(ISocketEventListener *pListener)
{
	Socket.SetEventListener(pListener);
}

// 送信.
void CPeerBase::Send(const char *pData, unsigned int Size)
{
	if (!IsValid()) { return; }

	Socket.Send(pData, Size);
}

// 切断.
void CPeerBase::Disconnect()
{
	// SocketのPoll処理中に切断される可能性があるので、
	// 即解体はせずにフラグだけ立てておく。
	// Poll処理後、切断フラグが立っていれば解体。
	bDisconnect = true;
}


// ソケット解放.
void CPeerBase::ReleaseSocket()
{
	Socket.Release(ESocketDisconnectReason::Destruct);
}

}
}
