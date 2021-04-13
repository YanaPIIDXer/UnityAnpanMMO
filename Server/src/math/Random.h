#ifndef RANDOM_H
#define RANDOM_H

class Random
{
public:
    // デストラクタ
    ~Random();

    // 0 ~ (Max - 1)までの乱数を取得
    int Next(int Max);

    // Min ~ (Max - 1)までの乱数を取得
    int Next(int Min, int Max);

private:
    // ============ Singleton ==========
public:
    static Random &GetInstance() { return Instance; }

private:
    Random();
    static Random Instance;
};

#endif // #ifndef RANDOM_H
