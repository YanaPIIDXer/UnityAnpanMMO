#ifndef CHARACTER_H
#define CHARACTER_H

#include "type.h"
#include "math/Vector.h"

class Area;

// キャラクタクラス
class Character
{
public:
    // コンストラクタ
    Character(uint InId, Area *pInArea, const Vector &InPosition, float InRotation);

    // デストラクタ
    virtual ~Character() = 0;

    // IDを取得
    uint GetId() const { return Id; }

    // 座標を取得
    const Vector &GetPosition() const { return Position; }

    // 回転を取得
    float GetRotation() const { return Rotation; }

    // 座標を設定
    void SetPosition(const Vector &NewPosition) { Position = NewPosition; }

    // 回転を設定
    void SetRotation(float NewRotation) { Rotation = NewRotation; }

    // 所属エリア取得
    Area *GetArea() const { return pArea; }

    // 所属エリア変更
    void ChangeArea(Area *pNewArea, const Vector &NewPosition, float NewRotation)
    {
        pArea = pNewArea;
        Position = NewPosition;
        Rotation = NewRotation;
    }

    // 定期処理
    void Poll(int DeltaTime);

protected:
    // 内部で呼び出す定期処理
    virtual void Update(int DeltaTime) {}

private:
    // ID
    uint Id;

    // 所属エリア
    Area *pArea;

    // 座標
    Vector Position;

    // 回転
    float Rotation;
};

#endif // #ifndef CHARACTER_H
