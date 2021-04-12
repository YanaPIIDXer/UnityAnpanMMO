#ifndef ENEMY_H
#define ENEMY_H

#include "character/Character.h"

// エネミークラス
class Enemy : public Character
{
public:
    // コンストラクタ
    Enemy(uint InId, Area *pInArea, const Vector &InPosition, float InRotation);

    // デストラクタ
    virtual ~Enemy();

protected:
private:
};

#endif // #ifndef ENEMY_H
