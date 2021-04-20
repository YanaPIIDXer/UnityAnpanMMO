#ifndef AREA_H
#define AREA_H

#include "character/player/PlayerManager.h"
#include "character/enemy/EnemyManager.h"

class Vector;
class Enemy;

// エリアクラス
class Area
{
public:
    // コンストラクタ
    Area();

    // デストラクタ
    ~Area();

    // 定期処理
    void Poll(int DeltaTime);

    // プレイヤー入場
    void JoinPlayer(Player *pPlayer, const Vector &Position, float Rotation);

    // プレイヤー退場
    void LeavePlayer(uint Id);

    // プレイヤーが移動した
    void OnPlayerMove(uint Id);

private:
    // プレイヤーマネージャ
    PlayerManager PlayerMgr;

    // エネミーマネージャ
    EnemyManager EnemyMgr;

    // エネミーが生成された
    void OnEnemySpawn(Enemy *pEnemy);
};

#endif // #ifndef AREA_H
