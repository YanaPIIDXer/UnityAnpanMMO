#ifndef AREAMANAGER_H
#define AREAMANAGER_H

// エリア管理クラス
class AreaManager
{
public:
    // デストラクタ
    ~AreaManager();

private:
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
