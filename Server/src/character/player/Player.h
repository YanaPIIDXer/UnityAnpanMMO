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

protected:
private:
    // 所有者
    Peer *pOwner;
};

#endif // #ifndef PLAYER_H
