#include "Peer.h"
#include "character/player/Player.h"
#include "YanaPOnlineUtil/Packet/Packet.h"
#include "peerstate/PeerStateTitle.h"

using namespace YanaPOnlineUtil::Packet;
using namespace YanaPOnlineUtil::Stream;

// コンストラクタ
Peer::Peer(uint InId, YanaPServer::Socket::ISocket *pSocket)
    : CPeerBase(pSocket), Id(InId), pState(new PeerStateTitle(this)),
      PacketSerializer(
          std::bind(&Peer::OnRecvPacket, this, std::placeholders::_1, std::placeholders::_2),
          std::bind(&Peer::Send, this, std::placeholders::_1, std::placeholders::_2)),
      pCharacter(nullptr)
{
}

// デストラクタ
Peer::~Peer()
{
}

// 受信した
void Peer::OnRecv(const char *pData, unsigned int Size)
{
    PacketSerializer.OnRecv(pData, Size);
}

// パケット送信
void Peer::SendPacket(CPacket *pPacket)
{
    PacketSerializer.Send(pPacket);
}

// Stateを設定
void Peer::SetState(PeerStateBase *pNewState)
{
    pState.reset(pNewState);
}

// プレイヤー構築
void Peer::ConfigureCharacter(const Vector &Position, float Rotation)
{
    pCharacter = PlayerPtr(new Player(this, Position, Rotation));
}

// パケットを受信した
void Peer::OnRecvPacket(byte PacketID, IMemoryStream *pStream)
{
    if (pState != nullptr)
    {
        pState->OnRecvPacket(PacketID, pStream);
    }
}
