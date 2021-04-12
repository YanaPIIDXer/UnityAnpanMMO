#include "Character.h"

// コンストラクタ
Character::Character(const Vector &InPosition, float InRotation)
    : Position(InPosition), Rotation(InRotation)
{
}

// デストラクタ
Character::~Character()
{
}
