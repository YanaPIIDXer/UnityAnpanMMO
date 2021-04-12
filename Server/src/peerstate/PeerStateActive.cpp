#include "PeerStateActive.h"
#include <iostream>

// コンストラクタ
PeerStateActive::PeerStateActive(Peer *pInParent)
    : PeerStateBase(pInParent)
{
    std::cout << "PeerStateActive::PeerStateActive" << std::endl;
}

// デストラクタ
PeerStateActive::~PeerStateActive()
{
}
