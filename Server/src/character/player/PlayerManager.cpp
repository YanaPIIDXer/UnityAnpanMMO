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
void PlayerManager::BroadcastPacket(CPacket *pPacket)
{
    for (auto It : PlayerMap)
    {
        It.second->GetOwner()->SendPacket(pPacket);
    }
}
