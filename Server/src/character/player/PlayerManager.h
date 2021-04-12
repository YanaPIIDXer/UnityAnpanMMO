#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include <memory>
#include <map>
#include "type.h"

class Player;

// プレイヤー管理クラス
class PlayerManager
{
public:
    // コンストラクタ
    PlayerManager();

    // デストラクタ
    ~PlayerManager();

    // 追加
    void Add(Player *pPlayer);

    // 削除
    void Remove(uint Id);

    // 取得
    Player *Get(uint Id) const;

private:
    // プレイヤーマップ
    std::map<uint, Player *> PlayerMap;
};

#endif // #ifndef PLAYERMANAGER_H
