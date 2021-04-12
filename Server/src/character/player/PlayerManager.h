#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include <memory>
#include <map>
#include "type.h"

class Player;
typedef std::shared_ptr<Player> PlayerPtr;

// プレイヤー管理クラス
class PlayerManager
{
public:
    // コンストラクタ
    PlayerManager();

    // デストラクタ
    ~PlayerManager();

private:
    // プレイヤーマップ
    std::map<uint, PlayerPtr> PlayerMap;
};

#endif // #ifndef PLAYERMANAGER_H
