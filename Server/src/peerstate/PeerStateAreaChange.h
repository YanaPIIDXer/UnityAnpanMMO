#ifndef PEERSTATEAREACHANGE_H
#define PEERSTATEAREACHANGE_H

#include "PeerStateBase.h"
#include "type.h"
#include "math/Vector.h"

// PeerState: エリア切り替え
class PeerStateAreaChange : public PeerStateBase
{
public:
    // コンストラクタ
    PeerStateAreaChange(Peer *pInParent, uint InAreaId, const Vector &InPosition, float InRotation);

    // デストラクタ
    virtual ~PeerStateAreaChange();

protected:
private:
    // エリアＩＤ
    uint AreaId;

    // 座標
    Vector Position;

    // 回転
    float Rotation;

    // ロード完了を受信した
    void OnRecvLoadEnd(IMemoryStream *pStream);
};

#endif // #ifndef PEERSTATEAREACHANGE_H
