#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <map>
#include <memory>
#include "type.h"
class Enemy;
typedef std::shared_ptr<Enemy> EnemyPtr;

// エネミーマネージャ
class EnemyManager
{
public:
    // コンストラクタ
    EnemyManager();

    // デストラクタ
    ~EnemyManager();

    // 定期処理
    void Poll(int DeltaTime);

    // 追加
    void Add(Enemy *pEnemy);

private:
    // エネミーマップ
    std::map<uint, EnemyPtr> EnemyMap;
};

#endif // #ifndef ENEMYMANAGER_H
