#include "SimpleTimer.h"

// コンストラクタ
SimpleTimer::SimpleTimer(int InInterval, const std::function<void()> &CallbackFunc)
    : Interval(InInterval), ElapsedTime(0), Callback(CallbackFunc)
{
}

// デストラクタ
SimpleTimer::~SimpleTimer()
{
}

// 定期処理
void SimpleTimer::Poll(int DeltaTime)
{
    ElapsedTime += DeltaTime;
    if (ElapsedTime >= Interval)
    {
        Callback();
        ElapsedTime -= Interval;
    }
}
