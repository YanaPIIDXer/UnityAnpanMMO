#ifndef PEER_H
#define PEER_H

#include <memory>
#include "YanaPServer/Peer/PeerBase.h"
#include "YanaPOnlineUtil/Packet/PacketSerializer.h"
#include "type.h"

using namespace YanaPServer::Peer;
using namespace YanaPOnlineUtil::Packet;

class PeerStateBase;

// Peer
class Peer : public CPeerBase
{
public:
    // コンストラクタ
    Peer(YanaPServer::Socket::ISocket *pSocket);

    // デストラクタ
    virtual ~Peer();

    // 受信した
    virtual void OnRecv(const char *pData, unsigned int Size) override;

    // パケット送信
    void SendPacket(YanaPOnlineUtil::Packet::CPacket *pPacket);

    // Stateを設定
    void SetState(PeerStateBase *pNewState);

protected:
private:
    // State
    std::shared_ptr<PeerStateBase> pState;

    // パケットシリアライザ
    CPacketSerializer PacketSerializer;

    // パケットを受信した
    void OnRecvPacket(byte PacketID, YanaPOnlineUtil::Stream::IMemoryStream *pStream);
};

#endif // #ifndef PEER_H
