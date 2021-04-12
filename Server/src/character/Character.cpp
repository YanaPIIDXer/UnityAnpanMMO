#include "Character.h"

// コンストラクタ
Character::Character(uint InId, const Vector &InPosition, float InRotation)
    : Id(InId), Position(InPosition), Rotation(InRotation)
{
}

// デストラクタ
Character::~Character()
{
}
