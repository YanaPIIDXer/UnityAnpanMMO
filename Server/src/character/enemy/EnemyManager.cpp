#include "EnemyManager.h"
#include "Enemy.h"

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

    // TODO:乱数で散らせる
    Vector Pos(0, 0, 0);
    float Rot = 0;

    Enemy *pEnemy = new Enemy(NextId, pArea, Pos, Rot);
    EnemyMap[NextId] = EnemyPtr(pEnemy);
    NextId++;
}