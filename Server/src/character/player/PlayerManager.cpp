#include "PlayerManager.h"
#include "character/player/Player.h"
#include "core/Peer.h"

// コンストラクタ
PlayerManager::PlayerManager()
{
}

// デストラクタ
PlayerManager::~PlayerManager()
{
}

// 定期処理
void PlayerManager::Poll(int DeltaTime)
{
    for (auto It : PlayerMap)
    {
        It.second->Poll(DeltaTime);
    }
}

// 追加
void PlayerManager::Add(Player *pPlayer)
{
    uint Id = pPlayer->GetId();
    PlayerMap[Id] = pPlayer;
}

// 削除
void PlayerManager::Remove(uint Id)
{
    if (PlayerMap.find(Id) == PlayerMap.end())
    {
        return;
    }

    PlayerMap.erase(Id);
}

// 取得
Player *PlayerManager::Get(uint Id) const
{
    auto It = PlayerMap.find(Id);
    if (It == PlayerMap.end())
    {
        return nullptr;
    }
    return It->second;
}

// パケットをバラ撒く
void PlayerManager::BroadcastPacket(CPacket *pPacket, uint IgnoreId)
{
    for (auto It : PlayerMap)
    {
        if (It.second->GetId() == IgnoreId)
        {
            continue;
        }
        It.second->GetOwner()->SendPacket(pPacket);
    }
}
