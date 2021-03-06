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

// 定期処理
void Character::Poll(int DeltaTime)
{
    Update(DeltaTime);
}
