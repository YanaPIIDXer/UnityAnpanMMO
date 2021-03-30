#include "Application.h"
#include "Peer.h"

// コンストラクタ
Application::Application()
    : CApplicationBase([](PeerPtr pPeer) {})
{
}

// デストラクタ
Application::~Application()
{
}

// Peer生成
CPeerBase *Application::CreatePeer(YanaPServer::Socket::ISocket *pSocket)
{
    return new Peer(pSocket);
}
