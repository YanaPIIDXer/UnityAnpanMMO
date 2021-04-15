#ifndef PEERSTATEACTIVE_H
#define PEERSTATEACTIVE_H

#include "PeerStateBase.h"
#include "type.h"

// PeerState: アクティブ
class PeerStateActive : public PeerStateBase
{
public:
    // コンストラクタ
    PeerStateActive(Peer *pInParent, uint InAreaId);

    // デストラクタ
    virtual ~PeerStateActive();

protected:
private:
    // エリアID
    uint AreaId;
};

#endif // #ifndef PEERSTATEACTIVE_H
