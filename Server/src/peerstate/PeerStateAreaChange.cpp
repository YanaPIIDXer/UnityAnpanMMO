#include "PeerStateAreaChange.h"
#include "core/Peer.h"
#include "packet/PacketAreaChange.h"
#include "packet/PacketPlayerPositionChange.h"
#include "PeerStateActive.h"
#include "area/AreaManager.h"
#include "area/Area.h"

// コンストラクタ
PeerStateAreaChange::PeerStateAreaChange(Peer *pInParent, uint InAreaId, const Vector &InPosition, float InRotation)
    : PeerStateBase(pInParent), AreaId(InAreaId), Position(InPosition), Rotation(InRotation)
{
    AddPacketFunc(PacketID::AreaLoadEnd, std::bind(&PeerStateAreaChange::OnRecvLoadEnd, this, std::placeholders::_1));

    PacketAreaChange Packet(AreaId);
    pInParent->SendPacket(&Packet);
}

// デストラクタ
PeerStateAreaChange::~PeerStateAreaChange()
{
}

// ロード完了を受信した
void PeerStateAreaChange::OnRecvLoadEnd(IMemoryStream *pStream)
{
    PositionPack PosPack(Position.X, Position.Y, Position.Z, Rotation);
    PacketPlayerPositionChange Packet(PosPack);
    SendPacket(&Packet);

    AreaManager::GetInstance().Get(AreaId).lock()->JoinPlayer(GetParent()->GetCharacter(), Position, Rotation);
    SetNextState(new PeerStateActive(GetParent(), AreaId));
}
