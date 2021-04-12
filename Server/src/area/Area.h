#ifndef AREA_H
#define AREA_H

#include "character/player/PlayerManager.h"

// エリアクラス
class Area
{
public:
    // コンストラクタ
    Area();

    // デストラクタ
    ~Area();

private:
    // プレイヤーマネージャ
    PlayerManager PlayerMgr;
};

#endif // #ifndef AREA_H
