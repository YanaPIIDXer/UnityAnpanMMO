#ifndef SIMPLETIMER_H
#define SIMPLETIMER_H

#include <functional>

// シンプルなタイマー
class SimpleTimer
{
public:
    // コンストラクタ
    SimpleTimer(int InInterval, const std::function<void()> &CallbackFunc);

    // デストラクタ
    ~SimpleTimer();

    // 定期処理
    void Poll(int DeltaTime);

private:
    // インターバル
    const int Interval;

    // 経過時間
    int ElapsedTime;

    // 生成コールバック
    std::function<void()> Callback;
};

#endif // #ifndef SIMPLETIMER_H
