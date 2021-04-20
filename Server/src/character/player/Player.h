#ifndef PLAYER_H
#define PLAYER_H

#include "character/Character.h"
class Peer;

// プレイヤークラス
class Player : public Character
{
public:
    // コンストラクタ
    Player(Peer *pInOwner, const Vector &InPosition, float InRotation);

    // デストラクタ
    virtual ~Player();

    // 所有者を取得
    Peer *GetOwner() const { return pOwner; }

    // 移動
    void Move(const Vector &Position, float Rotation);

protected:
private:
    // 所有者
    Peer *pOwner;
};

#endif // #ifndef PLAYER_H
