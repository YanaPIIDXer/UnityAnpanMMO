#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include <memory>
#include <map>
#include "type.h"

class Player;

namespace YanaPOnlineUtil::Packet
{
    class CPacket;
}
using namespace YanaPOnlineUtil::Packet;

// プレイヤー管理クラス
class PlayerManager
{
public:
    // コンストラクタ
    PlayerManager();

    // デストラクタ
    ~PlayerManager();

    // 定期処理
    void Poll(int DeltaTime);

    // 追加
    void Add(Player *pPlayer);

    // 削除
    void Remove(uint Id);

    // 取得
    Player *Get(uint Id) const;

    // パケットをバラ撒く
    // TODO:距離を指定できるようにする
    void BroadcastPacket(CPacket *pPacket);

private:
    // プレイヤーマップ
    std::map<uint, Player *> PlayerMap;
};

#endif // #ifndef PLAYERMANAGER_H
