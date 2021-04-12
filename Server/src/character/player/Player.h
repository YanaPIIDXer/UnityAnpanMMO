#ifndef PLAYER_H
#define PLAYER_H

#include "character/Character.h"

// プレイヤークラス
class Player : public Character
{
public:
    // コンストラクタ
    Player(const Vector &InPosition, float InRotation);

    // デストラクタ
    virtual ~Player();

protected:
private:
};

#endif // #ifndef PLAYER_H
