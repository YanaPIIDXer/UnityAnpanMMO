#include "Peer.h"
#include <iostream>

// コンストラクタ
Peer::Peer(YanaPServer::Socket::ISocket *pSocket)
    : CPeerBase(pSocket)
{
}

// デストラクタ
Peer::~Peer()
{
}

// 接続された
void Peer::OnConnect()
{
    // ここ呼ばれないんじゃね？
    std::cout << "Peer::OnConnect" << std::endl;
}

// 切断された
void Peer::OnDisconnect(ESocketDisconnectReason Reason)
{
    std::cout << "Peer:OnDisconnect" << std::endl;
}

// 受信した
void Peer::OnRecv(const char *pData, unsigned int Size)
{
}
