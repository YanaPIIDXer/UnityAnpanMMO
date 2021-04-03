#ifndef PEER_H
#define PEER_H

#include <memory>
#include "YanaPServer/Peer/PeerBase.h"
using namespace YanaPServer::Peer;
using namespace YanaPServer::Socket;

namespace YanaPOnlineUtil::Packet
{
    class CPacket;
}

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
    void SetState(PeerStateBase *pNewState) { pState.reset(pNewState); }

protected:
private:
    // State
    std::shared_ptr<PeerStateBase> pState;
};

#endif // #ifndef PEER_H
