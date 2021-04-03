#include "PeerStateBase.h"
#include "core/Peer.h"
#include "packet/PacketPing.h"
#include "YanaPOnlineUtil/Stream/MemoryStream.h"

// コンストラクタ
PeerStateBase::PeerStateBase(Peer *pInParent)
    : pParent(pInParent)
{
}

// デストラクタ
PeerStateBase::~PeerStateBase()
{
}
// パケットを受信した
void PeerStateBase::OnRecvPacket(byte PacketID, YanaPOnlineUtil::Stream::IMemoryStream *pStream)
{
    auto Func = PacketFuncMap.find(PacketID);
    if (Func != PacketFuncMap.end())
    {
        Func->second(pStream);
    }
}
