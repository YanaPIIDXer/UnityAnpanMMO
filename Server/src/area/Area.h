#ifndef AREA_H
#define AREA_H

#include "character/player/PlayerManager.h"

class Vector;

// エリアクラス
class Area
{
public:
    // コンストラクタ
    Area();

    // デストラクタ
    ~Area();

    // プレイヤー入場
    void JoinPlayer(Player *pPlayer, const Vector &Position, float Rotation);

    // プレイヤー退場
    void LeavePlayer(uint Id);

private:
    // プレイヤーマネージャ
    PlayerManager PlayerMgr;
};

#endif // #ifndef AREA_H
