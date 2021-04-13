#include "Area.h"
#include "character/player/Player.h"

// コンストラクタ
Area::Area()
    : EnemyMgr(this)
{
}

// デストラクタ
Area::~Area()
{
}

// 定期処理
void Area::Poll(int DeltaTime)
{
    PlayerMgr.Poll(DeltaTime);
    EnemyMgr.Poll(DeltaTime);
}

// プレイヤー入場
void Area::JoinPlayer(Player *pPlayer, const Vector &Position, float Rotation)
{
    PlayerMgr.Add(pPlayer);
    pPlayer->ChangeArea(this, Position, Rotation);
}

// プレイヤー退場
void Area::LeavePlayer(uint Id)
{
    PlayerMgr.Remove(Id);
}
