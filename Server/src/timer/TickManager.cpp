#include "TickManager.h"

#include <iostream>

TickManager TickManager::Instance;

// コンストラクタ
TickManager::TickManager()
{
    PrevTime = std::chrono::system_clock::now();
}

// 毎フレームの処理.
void TickManager::Poll()
{
    std::chrono::system_clock::time_point CurrentTime = std::chrono::system_clock::now();
    int DeltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(CurrentTime - PrevTime).count();
    if (DeltaTime < 0)
    {
        // たまにCurrentTime < PrevTimeになるようなので対処。
        DeltaTime = 0;
    }

    for (unsigned int i = 0; i < Functions.size(); i++)
    {
        Functions[i](DeltaTime);
    }

    PrevTime = CurrentTime;
}

// 追加.
void TickManager::Add(const TickFunction &Function)
{
    Functions.push_back(Function);
}
