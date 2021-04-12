#ifndef PEER_H
#define PEER_H

#include <memory>
#include "YanaPServer/Peer/PeerBase.h"
#include "YanaPOnlineUtil/Packet/PacketSerializer.h"
#include "type.h"

using namespace YanaPServer::Peer;
using namespace YanaPOnlineUtil::Packet;

class PeerStateBase;
class Player;
typedef std::shared_ptr<Player> PlayerPtr;
class Vector;

// Peer
class Peer : public CPeerBase
{
public:
    // コンストラクタ
    Peer(uint InId, YanaPServer::Socket::ISocket *pSocket);

    // デストラクタ
    virtual ~Peer();

    // 受信した
    virtual void OnRecv(const char *pData, unsigned int Size) override;

    // パケット送信
    void SendPacket(YanaPOnlineUtil::Packet::CPacket *pPacket);

    // Stateを設定
    void SetState(PeerStateBase *pNewState);

    // ID取得
    uint GetId() const { return Id; }

    // キャラクタ取得
    Player *GetCharacter() const { return pCharacter.get(); }

    // プレイヤー構築
    void ConfigureCharacter(const Vector &Position, float Rotation);

protected:
private:
    // ID
    uint Id;

    // State
    std::shared_ptr<PeerStateBase> pState;

    // パケットシリアライザ
    CPacketSerializer PacketSerializer;

    // 自キャラ
    PlayerPtr pCharacter;

    // パケットを受信した
    void OnRecvPacket(byte PacketID, YanaPOnlineUtil::Stream::IMemoryStream *pStream);
};

#endif // #ifndef PEER_H
