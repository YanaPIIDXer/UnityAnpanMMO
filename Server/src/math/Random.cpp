#include "Random.h"
#include <math.h>
#include <time.h>

Random Random::Instance;

// コンストラクタ
Random::Random()
{
    srand((unsigned int)time(nullptr));
}

// デストラクタ
Random::~Random()
{
}

// 0 ~ (Max - 1)までの乱数を取得
int Random::Next(int Max)
{
    return rand() % Max;
}

// Min ~ (Max - 1)までの乱数を取得
int Random::Next(int Min, int Max)
{
    return rand() % (Max - Min) + Min;
}
