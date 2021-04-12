#ifndef TICKMANAGER_H
#define TICKMANAGER_H

#include <functional>
#include <vector>
#include <chrono>

// 定期処理管理クラス
class TickManager
{

private: // 別名定義.
    typedef std::function<void(int)> TickFunction;

public:
    // デストラクタ
    ~TickManager() {}

    // 毎フレームの処理.
    void Poll();

    // 追加.
    void Add(const TickFunction &Function);

private:
    // 以前の時間.
    std::chrono::system_clock::time_point PrevTime;

    // 関数リスト
    std::vector<TickFunction> Functions;

    // ========== Singleton ============
public:
    static TickManager &GetInstance() { return Instance; }

private:
    // コンストラクタ
    TickManager();
    static TickManager Instance;
};

#endif // #ifndef TICKMANAGER_H
