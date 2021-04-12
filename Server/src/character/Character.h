#ifndef CHARACTER_H
#define CHARACTER_H

#include "math/Vector.h"

// キャラクタクラス
class Character
{
public:
    // コンストラクタ
    Character(const Vector &InPosition, float InRotation);

    // デストラクタ
    virtual ~Character() = 0;

protected:
private:
    // 座標
    Vector Position;

    // 回転
    float Rotation;
};

#endif // #ifndef CHARACTER_H
