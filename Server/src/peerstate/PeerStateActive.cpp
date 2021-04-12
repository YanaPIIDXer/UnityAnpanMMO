#include "PeerStateActive.h"
#include <iostream>
#include "core/Peer.h"
#include "math/Vector.h"

// コンストラクタ
PeerStateActive::PeerStateActive(Peer *pInParent)
    : PeerStateBase(pInParent)
{
    // TODO:本来ならDBから引っ張ってきたデータを放り込む
    GetParent()->ConfigureCharacter(Vector::Zero, 0.0f);
}

// デストラクタ
PeerStateActive::~PeerStateActive()
{
}
