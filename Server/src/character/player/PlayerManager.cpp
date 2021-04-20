#include "PlayerManager.h"
#include "character/player/Player.h"
#include "core/Peer.h"
#include "packet/PacketPlayerEntry.h"
#include "packet/PacketPlayerList.h"
#include "packet/PacketPlayerMoved.h"

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
    // まずは他キャラリストを取得して送信
    FlexArray<PlayerData> List;
    for (auto It : PlayerMap)
    {
        const auto &Position = It.second->GetPosition();
        List.PushBack(PlayerData(It.second->GetId(), PositionPack(Position.X, Position.Y, Position.Z, It.second->GetRotation())));
    }
    PacketPlayerList ListPacket(List);
    pPlayer->GetOwner()->SendPacket(&ListPacket);

    uint Id = pPlayer->GetId();
    PlayerMap[Id] = pPlayer;

    // 他のキャラに追加を通知
    const auto &Position = pPlayer->GetPosition();
    PacketPlayerEntry EntryPacket(PlayerData(Id, PositionPack(Position.X, Position.Y, Position.Z, pPlayer->GetRotation())));
    BroadcastPacket(&EntryPacket, Id);
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

// プレイヤーが移動した
void PlayerManager::OnPlayerMove(uint Id)
{
    auto It = PlayerMap.find(Id);
    if (It == PlayerMap.end())
    {
        return;
    }
    Vector Position = It->second->GetPosition();
    float Rotation = It->second->GetRotation();
    PacketPlayerMoved Packet(Id, PositionPack(Position.X, Position.Y, Position.Z, Rotation));
    BroadcastPacket(&Packet, Id);
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
