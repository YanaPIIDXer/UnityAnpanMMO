#include "Character.h"

// コンストラクタ
Character::Character(uint InId, Area *pInArea, const Vector &InPosition, float InRotation)
    : Id(InId), pArea(pInArea), Position(InPosition), Rotation(InRotation)
{
}

// デストラクタ
Character::~Character()
{
}
