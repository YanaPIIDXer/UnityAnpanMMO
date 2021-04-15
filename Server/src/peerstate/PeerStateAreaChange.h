#ifndef PEERSTATEAREACHANGE_H
#define PEERSTATEAREACHANGE_H

#include "PeerStateBase.h"

// PeerState: エリア切り替え
class PeerStateAreaChange : public PeerStateBase
{
public:
    // コンストラクタ
    PeerStateAreaChange(Peer *pInParent);

    // デストラクタ
    virtual ~PeerStateAreaChange();

protected:
private:
};

#endif // #ifndef PEERSTATEAREACHANGE_H
