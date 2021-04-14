#include "Area.h"
#include "character/player/Player.h"
#include "character/enemy/Enemy.h"
#include "core/Peer.h"
#include "packet/PacketEnemyEntry.h"
#include "packet/PacketEnemyList.h"

// コンストラクタ
Area::Area()
    : EnemyMgr(this, std::bind(&Area::OnEnemySpawn, this, std::placeholders::_1))
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

    FlexArray<EnemyData> Enemys;
    EnemyMgr.MakeEnemyList(Enemys);
    PacketEnemyList Packet(Enemys);
    pPlayer->GetOwner()->SendPacket(&Packet);
}

// プレイヤー退場
void Area::LeavePlayer(uint Id)
{
    PlayerMgr.Remove(Id);
}

// エネミーが生成された
void Area::OnEnemySpawn(Enemy *pEnemy)
{
    const Vector &Pos = pEnemy->GetPosition();
    float Rotation = pEnemy->GetRotation();
    PositionPack Pack(Pos.X, Pos.Y, Pos.Z, Rotation);
    EnemyData Data(Pack);
    PacketEnemyEntry Packet(Data);
    PlayerMgr.BroadcastPacket(&Packet);
}
