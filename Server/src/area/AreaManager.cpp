#include "AreaManager.h"

AreaManager AreaManager::Instance;

// コンストラクタ
AreaManager::AreaManager()
{
}

// デストラクタ
AreaManager::~AreaManager()
{
}

// エリア取得
std::weak_ptr<Area> AreaManager::Get(uint Id) const
{
    auto It = AreaMap.find(Id);
    if (It == AreaMap.end())
    {
        return std::weak_ptr<Area>();
    }

    return It->second;
}
