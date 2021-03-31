#include "Peer.h"
#include <iostream>

// コンストラクタ
Peer::Peer(YanaPServer::Socket::ISocket *pSocket)
    : CPeerBase(pSocket)
{
    std::cout << "Peer::Peer" << std::endl;
}

// デストラクタ
Peer::~Peer()
{
    std::cout << "Peer::~Peer" << std::endl;
}

// 受信した
void Peer::OnRecv(const char *pData, unsigned int Size)
{
}
