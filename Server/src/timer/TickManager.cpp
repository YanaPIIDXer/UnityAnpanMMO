#include "TickManager.h"
#include <time.h>

TickManager TickManager::Instance;

// コンストラクタ
TickManager::TickManager()
{
    clock_gettime(CLOCK_REALTIME, &PrevTime);
}

// 毎フレームの処理.
void TickManager::Poll()
{
    timespec CurrentTime;
    clock_gettime(CLOCK_REALTIME, &CurrentTime);
    int DeltaTime = (CurrentTime.tv_nsec - PrevTime.tv_nsec) / 1000000;
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
