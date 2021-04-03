#include "PeerStateBase.h"
#include "core/Peer.h"
#include "packet/PacketPing.h"

// コンストラクタ
PeerStateBase::PeerStateBase(Peer *pInParent)
    : pParent(pInParent)
{
}

// デストラクタ
PeerStateBase::~PeerStateBase()
{
}
