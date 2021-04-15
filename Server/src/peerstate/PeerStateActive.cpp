#include "PeerStateActive.h"
#include <iostream>
#include "core/Peer.h"
#include "area/AreaManager.h"
#include "area/Area.h"

// コンストラクタ
PeerStateActive::PeerStateActive(Peer *pInParent, uint InAreaId)
    : PeerStateBase(pInParent), AreaId(InAreaId)
{
}

// デストラクタ
PeerStateActive::~PeerStateActive()
{
    AreaManager::GetInstance().Get(AreaId).lock()->LeavePlayer(GetParent()->GetId());
}
