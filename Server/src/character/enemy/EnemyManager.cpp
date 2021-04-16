#include "EnemyManager.h"
#include "Enemy.h"
#include "math/Random.h"
#include "packet/EnemyData.h"

// コンストラクタ
EnemyManager::EnemyManager(Area *pInArea, const std::function<void(Enemy *)> &InSpawnCallback)
    : pArea(pInArea), SpawnTimer(10000, std::bind(&EnemyManager::OnSpawn, this)), NextId(1), SpawnCallback(InSpawnCallback)
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

// エネミーリスト構築
void EnemyManager::MakeEnemyList(FlexArray<EnemyData> &List)
{
    for (auto It : EnemyMap)
    {
        EnemyPtr pEnemy = It.second;
        const Vector &Pos = pEnemy->GetPosition();
        float Rot = pEnemy->GetRotation();
        PositionPack Pack(Pos.X, Pos.Y, Pos.Z, Rot);
        EnemyData Data(pEnemy->GetId(), Pack);
        List.PushBack(Data);
    }
}

// 生成コールバック
void EnemyManager::OnSpawn()
{
    if (EnemyMap.size() > 20)
    {
        return;
    }

    Vector Pos(Random::GetInstance().Next(-100, 100), Random::GetInstance().Next(-10, 10), 0);
    float Rot = 0;

    Enemy *pEnemy = new Enemy(NextId, pArea, Pos, Rot);
    EnemyMap[NextId] = EnemyPtr(pEnemy);
    NextId++;

    SpawnCallback(pEnemy);
}
