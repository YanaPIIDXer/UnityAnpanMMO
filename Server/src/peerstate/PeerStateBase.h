#ifndef PEERSTATEBASE_H
#define PEERSTATEBASE_H

class Peer;

// PeerのState基底クラス
class PeerStateBase
{
public:
    // コンストラクタ
    PeerStateBase(Peer *pInParent);

    // デストラクタ
    virtual ~PeerStateBase() = 0;

protected:
private:
    // 親
    Peer *pParent;
};

#endif // #ifndef PEERSTATEBASE_H
