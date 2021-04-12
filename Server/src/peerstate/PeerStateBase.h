#ifndef PEERSTATEBASE_H
#define PEERSTATEBASE_H

#include <map>
#include <functional>
#include "type.h"

namespace YanaPOnlineUtil::Stream
{
    class IMemoryStream;
}

using namespace YanaPOnlineUtil::Stream;

namespace YanaPOnlineUtil::Packet
{
    class CPacket;
}

using namespace YanaPOnlineUtil::Packet;

class Peer;
typedef std::function<void(IMemoryStream *)> PacketFunc;

// PeerのState基底クラス
class PeerStateBase
{
public:
    // コンストラクタ
    PeerStateBase(Peer *pInParent);

    // デストラクタ
    virtual ~PeerStateBase() = 0;

    // パケットを受信した
    void OnRecvPacket(byte PacketID, IMemoryStream *pStream);

protected:
    // パケット関数追加
    void AddPacketFunc(byte PacketID, const PacketFunc &Func)
    {
        PacketFuncMap[PacketID] = Func;
    }

    // パケット送信
    void SendPacket(CPacket *pPacket);

    // 次のStateを設定
    // ※実行時点で現在のStateは解体されるので注意する事
    void SetNextState(PeerStateBase *pNextState);

    // 親を取得
    Peer *GetParent() { return pParent; }

private:
    // 親
    Peer *pParent;

    // パケット関数マップ
    std::map<byte, PacketFunc> PacketFuncMap;

    // Pingを受信した
    void OnRecvPing(IMemoryStream *pStream);
};

#endif // #ifndef PEERSTATEBASE_H
