#include "Area.h"

// コンストラクタ
Area::Area()
{
}

// デストラクタ
Area::~Area()
{
}

// プレイヤー入場
void Area::JoinPlayer(Player *pPlayer)
{
    PlayerMgr.Add(pPlayer);
}

// プレイヤー退場
void Area::LeavePlayer(uint Id)
{
    PlayerMgr.Remove(Id);
}
