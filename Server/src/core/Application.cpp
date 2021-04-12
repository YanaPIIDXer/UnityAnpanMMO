#include "Application.h"
#include "Peer.h"

// コンストラクタ
Application::Application()
    : CApplicationBase([](PeerPtr pPeer) {}), NextPeerId(0)
{
}

// デストラクタ
Application::~Application()
{
}

// Peer生成
CPeerBase *Application::CreatePeer(YanaPServer::Socket::ISocket *pSocket)
{
    auto pPeer = new Peer(NextPeerId, pSocket);
    NextPeerId++;
    return pPeer;
}
