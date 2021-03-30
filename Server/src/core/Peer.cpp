#include "Peer.h"

// コンストラクタ
Peer::Peer(YanaPServer::Socket::ISocket *pSocket)
    : CPeerBase(pSocket)
{
}

// デストラクタ
Peer::~Peer()
{
}

// 受信した
void Peer::OnRecv(const char *pData, unsigned int Size)
{
}
