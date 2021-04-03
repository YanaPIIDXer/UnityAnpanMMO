#ifndef PEERSTATETITLE_H
#define PEERSTATETITLE_H

#include "PeerStateBase.h"

// タイトルステート
class PeerStateTitle : public PeerStateBase
{
public:
    // コンストラクタ
    PeerStateTitle(Peer *pInParent);

    // デストラクタ
    virtual ~PeerStateTitle();

protected:
private:
};

#endif // #ifndef PEERSTATETITLE_H
