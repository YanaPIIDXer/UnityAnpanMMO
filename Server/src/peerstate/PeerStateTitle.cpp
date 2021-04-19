#include "PeerStateTitle.h"
#include "PeerStateAreaChange.h"
#include "packet/PacketLogInRequest.h"
#include "packet/PacketLogInResult.h"
#include "core/Peer.h"
#include "math/Vector.h"

// コンストラクタ
PeerStateTitle::PeerStateTitle(Peer *pInParent)
    : PeerStateBase(pInParent)
{
    AddPacketFunc(PacketID::LogInRequest, std::bind(&PeerStateTitle::OnRecvLogIn, this, std::placeholders::_1));
}

// デストラクタ
PeerStateTitle::~PeerStateTitle()
{
}

// ログインパケットを受信した
void PeerStateTitle::OnRecvLogIn(IMemoryStream *pStream)
{
    PacketLogInRequest Request;
    if (!Request.Serialize(pStream))
    {
        return;
    }

    // 何もしていないのでとりあえず成功を返している
    PacketLogInResult Result(PacketLogInResult::ResultCode::Success);
    SendPacket(&Result);

    // TODO:本来ならDBから引っ張ってきたデータを放り込む
    uint AreaId = 1;
    Vector Position = Vector::Zero;
    float Rotation = 0.0f;
    GetParent()->ConfigureCharacter(Position, Rotation);

    SetNextState(new PeerStateAreaChange(GetParent(), AreaId, Position, Rotation));
}
