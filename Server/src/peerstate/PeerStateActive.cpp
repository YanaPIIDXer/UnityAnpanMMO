#include "PeerStateActive.h"
#include <iostream>
#include "core/Peer.h"
#include "area/AreaManager.h"
#include "area/Area.h"
#include "math/Vector.h"
#include "character/player/Player.h"
#include "packet/PacketPlayerMove.h"

// コンストラクタ
PeerStateActive::PeerStateActive(Peer *pInParent, uint InAreaId)
    : PeerStateBase(pInParent), AreaId(InAreaId)
{
    AddPacketFunc(PacketID::PlayerMove, std::bind(&PeerStateActive::OnRecvPlayerMove, this, std::placeholders::_1));
}

// デストラクタ
PeerStateActive::~PeerStateActive()
{
    AreaManager::GetInstance().Get(AreaId).lock()->LeavePlayer(GetParent()->GetId());
}

// プレイヤーの移動を受け取った
void PeerStateActive::OnRecvPlayerMove(IMemoryStream *pStream)
{
    PacketPlayerMove Packet;
    Packet.Serialize(pStream);

    Vector Position(Packet.Position.X, Packet.Position.Y, Packet.Position.Z);
    float Rotation = Packet.Position.Rotation;
    GetParent()->GetCharacter()->Move(Position, Rotation);
}
