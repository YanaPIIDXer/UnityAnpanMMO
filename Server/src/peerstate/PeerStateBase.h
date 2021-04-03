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
    // パケット関数追加
    void AddPacketFunc(byte PacketID, const PacketFunc &Func)
    {
        PacketFuncMap[PacketID] = Func;
    }

private:
    // 親
    Peer *pParent;

    // パケット関数マップ
    std::map<byte, PacketFunc> PacketFuncMap;
};

#endif // #ifndef PEERSTATEBASE_H
