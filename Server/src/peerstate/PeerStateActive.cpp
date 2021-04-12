#include "PeerStateActive.h"
#include <iostream>
#include "core/Peer.h"
#include "area/AreaManager.h"
#include "area/Area.h"
#include "math/Vector.h"

// コンストラクタ
PeerStateActive::PeerStateActive(Peer *pInParent)
    : PeerStateBase(pInParent)
{
    // TODO:本来ならローディングステートを挟む
    AreaManager::GetInstance().Get(1).lock()->JoinPlayer(GetParent()->GetCharacter(), Vector::Zero, 0.0f);
}

// デストラクタ
PeerStateActive::~PeerStateActive()
{
    AreaManager::GetInstance().Get(1).lock()->LeavePlayer(GetParent()->GetId());
}
