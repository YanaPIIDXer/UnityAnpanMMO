#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <map>
#include <memory>
#include "type.h"
#include "timer/SimpleTimer.h"
class Enemy;
typedef std::shared_ptr<Enemy> EnemyPtr;
class Area;

// エネミーマネージャ
class EnemyManager
{
public:
    // コンストラクタ
    EnemyManager(Area *pInArea);

    // デストラクタ
    ~EnemyManager();

    // 定期処理
    void Poll(int DeltaTime);

private:
    // 所属エリア
    Area *pArea;

    // エネミーマップ
    std::map<uint, EnemyPtr> EnemyMap;

    // 生成タイマー
    SimpleTimer SpawnTimer;

    // 次に割り振るID
    uint NextId;

    // 生成コールバック
    void OnSpawn();
};

#endif // #ifndef ENEMYMANAGER_H
