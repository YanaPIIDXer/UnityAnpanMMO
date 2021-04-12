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

    // 座標を取得
    const Vector &GetPosition() const { return Position; }

    // 回転を取得
    float GetRotation() const { return Rotation; }

    // 座標を設定
    void SetPosition(const Vector &NewPosition) { Position = NewPosition; }

    // 回転を設定
    void SetRotation(float NewRotation) { Rotation = NewRotation; }

protected:
private:
    // 座標
    Vector Position;

    // 回転
    float Rotation;
};

#endif // #ifndef CHARACTER_H
