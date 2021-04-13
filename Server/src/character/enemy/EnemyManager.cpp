#include "EnemyManager.h"
#include "Enemy.h"
#include "math/Random.h"

// コンストラクタ
EnemyManager::EnemyManager(Area *pInArea)
    : pArea(pInArea), SpawnTimer(10000, std::bind(&EnemyManager::OnSpawn, this)), NextId(1)
{
}

// デストラクタ
EnemyManager::~EnemyManager()
{
}

// 定期処理
void EnemyManager::Poll(int DeltaTime)
{
    for (auto It : EnemyMap)
    {
        It.second->Poll(DeltaTime);
    }

    SpawnTimer.Poll(DeltaTime);
}

// 生成コールバック
void EnemyManager::OnSpawn()
{
    if (EnemyMap.size() > 20)
    {
        return;
    }

    Vector Pos(Random::GetInstance().Next(-100, 100), Random::GetInstance().Next(-100, 100), 0);
    float Rot = 0;

    Enemy *pEnemy = new Enemy(NextId, pArea, Pos, Rot);
    EnemyMap[NextId] = EnemyPtr(pEnemy);
    NextId++;

    // TODO:周囲のクライアントへの通知をどげんかせんといかん
}
