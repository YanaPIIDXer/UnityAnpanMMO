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

private:
    // プレイヤーマップ
    std::map<uint, Player *> PlayerMap;
};

#endif // #ifndef PLAYERMANAGER_H
