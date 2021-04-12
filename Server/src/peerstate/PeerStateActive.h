#ifndef PEERSTATEACTIVE_H
#define PEERSTATEACTIVE_H

#include "PeerStateBase.h"

// PeerState: アクティブ
class PeerStateActive : public PeerStateBase
{
public:
    // コンストラクタ
    PeerStateActive(Peer *pInParent);

    // デストラクタ
    virtual ~PeerStateActive();

protected:
private:
};

#endif // #ifndef PEERSTATEACTIVE_H
