#include "Player.h"
#include "core/Peer.h"
#include "area/Area.h"

// コンストラクタ
Player::Player(Peer *pInOwner, const Vector &InPosition, float InRotation)
    : Character(pInOwner->GetId(), nullptr, InPosition, InRotation), pOwner(pInOwner)
{
}

// デストラクタ
Player::~Player()
{
}

// 移動
void Player::Move(const Vector &Position, float Rotation)
{
    SetPosition(Position);
    SetRotation(Rotation);

    GetArea()->OnPlayerMove(GetId());
}
