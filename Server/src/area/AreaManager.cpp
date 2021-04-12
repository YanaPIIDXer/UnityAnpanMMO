#include "AreaManager.h"
#include "Area.h"

AreaManager AreaManager::Instance;

// コンストラクタ
AreaManager::AreaManager()
{
}

// デストラクタ
AreaManager::~AreaManager()
{
}

// エリア生成
void AreaManager::Make(uint Id)
{
    if (AreaMap.find(Id) != AreaMap.end())
    {
        return;
    }

    AreaMap[Id] = AreaPtr(new Area());
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
