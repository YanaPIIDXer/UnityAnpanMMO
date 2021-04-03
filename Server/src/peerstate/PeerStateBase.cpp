#include "PeerStateBase.h"
#include "Peer/PeerBase.h"

// コンストラクタ
PeerStateBase::PeerStateBase(Peer *pInParent)
    : pParent(pInParent)
{
}

// デストラクタ
PeerStateBase::~PeerStateBase()
{
}
