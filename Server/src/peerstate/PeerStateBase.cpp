#include "PeerStateBase.h"
#include "core/Peer.h"
#include "packet/PacketPing.h"
#include "YanaPOnlineUtil/Stream/MemoryStream.h"

// コンストラクタ
PeerStateBase::PeerStateBase(Peer *pInParent)
    : pParent(pInParent)
{
    AddPacketFunc(PacketID::Ping, std::bind(&PeerStateBase::OnRecvPing, this, std::placeholders::_1));
}

// デストラクタ
PeerStateBase::~PeerStateBase()
{
}

// パケットを受信した
void PeerStateBase::OnRecvPacket(byte PacketID, IMemoryStream *pStream)
{
    auto Func = PacketFuncMap.find(PacketID);
    if (Func != PacketFuncMap.end())
    {
        Func->second(pStream);
    }
}

// パケット送信
void PeerStateBase::SendPacket(CPacket *pPacket)
{
    pParent->SendPacket(pPacket);
}

// 次のStateを設定
void PeerStateBase::SetNextState(PeerStateBase *pNextState)
{
    pParent->SetState(pNextState);
}

// Pingを受信した
void PeerStateBase::OnRecvPing(IMemoryStream *pStream)
{
    PacketPing Ping;
    SendPacket(&Ping);
}
