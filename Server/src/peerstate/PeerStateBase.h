#ifndef PEERSTATEBASE_H
#define PEERSTATEBASE_H

#include <map>
#include <functional>
#include "type.h"

class Peer;
typedef std::function<void(byte)> PacketFunc;

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

    // パケット関数マップ
    std::map<byte, PacketFunc> PacketFuncMap;
};

#endif // #ifndef PEERSTATEBASE_H
