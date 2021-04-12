#include "Player.h"
#include "core/Peer.h"

// コンストラクタ
Player::Player(Peer *pInOwner, const Vector &InPosition, float InRotation)
    : Character(pInOwner->GetId(), InPosition, InRotation), pOwner(pInOwner)
{
}

// デストラクタ
Player::~Player()
{
}
