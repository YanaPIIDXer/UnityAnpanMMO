#include "Peer.h"
#include <iostream>
#include "YanaPOnlineUtil/Packet/Packet.h"
#include "YanaPOnlineUtil/Stream/MemoryStreamWriter.h"
#include "YanaPOnlineUtil/Stream/MemorySizeCaliculator.h"

using namespace YanaPOnlineUtil::Packet;
using namespace YanaPOnlineUtil::Stream;

// コンストラクタ
Peer::Peer(YanaPServer::Socket::ISocket *pSocket)
    : CPeerBase(pSocket), pState(nullptr)
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

// パケット送信
void Peer::SendPacket(CPacket *pPacket)
{
    CMemorySizeCaliculator SizeStream;
    pPacket->Serialize(&SizeStream);

    CMemoryStreamWriter Stream(SizeStream.GetSize());
    pPacket->Serialize(&Stream);

    Send(Stream.GetBuffer(), Stream.GetSize());
}
