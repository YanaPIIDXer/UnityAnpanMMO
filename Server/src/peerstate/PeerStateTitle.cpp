#include "PeerStateTitle.h"
#include "PeerStateActive.h"
#include "packet/PacketID.h"

// コンストラクタ
PeerStateTitle::PeerStateTitle(Peer *pInParent)
    : PeerStateBase(pInParent)
{
    AddPacketFunc(PacketID::LogIn, std::bind(&PeerStateTitle::OnRecvLogIn, this, std::placeholders::_1));
}

// デストラクタ
PeerStateTitle::~PeerStateTitle()
{
}

// ログインパケットを受信した
void PeerStateTitle::OnRecvLogIn(IMemoryStream *pStream)
{
    // TODO:実装
}
