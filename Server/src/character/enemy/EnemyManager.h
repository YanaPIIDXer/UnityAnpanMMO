#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <map>
#include <memory>
#include <functional>
#include "type.h"
#include "timer/SimpleTimer.h"
#include "util/FlexArray.h"
class Enemy;
typedef std::shared_ptr<Enemy> EnemyPtr;
class Area;
class EnemyData;

// エネミーマネージャ
class EnemyManager
{
public:
    // コンストラクタ
    EnemyManager(Area *pInArea, const std::function<void(Enemy *)> &InSpawnCallback);

    // デストラクタ
    ~EnemyManager();

    // 定期処理
    void Poll(int DeltaTime);

    // エネミーリスト構築
    void MakeEnemyList(FlexArray<EnemyData> &List);

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

    // 生成コールバック
    std::function<void(Enemy *)> SpawnCallback;
};

#endif // #ifndef ENEMYMANAGER_H
