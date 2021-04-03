#include "Peer.h"
#include <iostream>
#include "YanaPOnlineUtil/Packet/Packet.h"
#include "peerstate/PeerStateBase.h"

using namespace YanaPOnlineUtil::Packet;
using namespace YanaPOnlineUtil::Stream;

// コンストラクタ
Peer::Peer(YanaPServer::Socket::ISocket *pSocket)
    : CPeerBase(pSocket), pState(nullptr),
      PacketSerializer(
          std::bind(&Peer::OnRecvPacket, this, std::placeholders::_1, std::placeholders::_2),
          std::bind(&Peer::Send, this, std::placeholders::_1, std::placeholders::_2))
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
    PacketSerializer.OnRecv(pData, Size);
}

void Peer::SetState(PeerStateBase *pNewState)
{
    pState.reset(pNewState);
}

// パケットを受信した
void Peer::OnRecvPacket(byte PacketID, IMemoryStream *pStream)
{
    if (pState != nullptr)
    {
    }
}
