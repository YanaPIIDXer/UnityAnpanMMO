#ifndef AREAMANAGER_H
#define AREAMANAGER_H

#include <memory>
#include <map>
#include "type.h"
class Area;
typedef std::shared_ptr<Area> AreaPtr;

// エリア管理クラス
class AreaManager
{
public:
    // デストラクタ
    ~AreaManager();

private:
    // エリアマップ
    std::map<uint, AreaPtr> AreaMap;

    // ========== Singleton ==========
public:
    // インスタンス取得
    static AreaManager &GetInstance() { return Instance; }

private:
    // コンストラクタ
    AreaManager();
    // インスタンス
    static AreaManager Instance;
};

#endif // #ifndef AREAMANAGER_H
