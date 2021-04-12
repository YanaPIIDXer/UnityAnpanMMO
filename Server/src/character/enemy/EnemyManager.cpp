#include "EnemyManager.h"
#include "Enemy.h"

// コンストラクタ
EnemyManager::EnemyManager()
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
}

// 追加
void EnemyManager::Add(Enemy *pEnemy)
{
    EnemyMap[pEnemy->GetId()] = EnemyPtr(pEnemy);
}
