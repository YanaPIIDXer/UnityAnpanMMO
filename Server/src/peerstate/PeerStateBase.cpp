#include "PeerStateBase.h"
#include "core/Peer.h"

// コンストラクタ
PeerStateBase::PeerStateBase(Peer *pInParent)
    : pParent(pInParent)
{
}

// デストラクタ
PeerStateBase::~PeerStateBase()
{
}
