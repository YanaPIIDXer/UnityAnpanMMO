#include "Player.h"

// コンストラクタ
Player::Player(uint InId, const Vector &InPosition, float InRotation)
    : Character(InId, InPosition, InRotation)
{
}

// デストラクタ
Player::~Player()
{
}
