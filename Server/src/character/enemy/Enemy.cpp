#include "Enemy.h"

// コンストラクタ
Enemy::Enemy(uint InId, Area *pInArea, const Vector &InPosition, float InRotation)
    : Character(InId, pInArea, InPosition, InRotation)
{
}

// デストラクタ
Enemy::~Enemy()
{
}
