#ifndef PEER_H
#define PEER_H

#include "YanaPServer/Peer/PeerBase.h"
using namespace YanaPServer::Peer;
using namespace YanaPServer::Socket;

namespace YanaPOnlineUtil::Packet
{
    class CPacket;
}

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

protected:
private:
};

#endif // #ifndef PEER_H
