#include "PeerStateTitle.h"
#include "PeerStateActive.h"
#include "packet/PacketLogInRequest.h"
#include "Packet/PacketLogInResult.h"
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
    GetParent()->ConfigureCharacter(Vector::Zero, 0.0f);

    SetNextState(new PeerStateActive(GetParent()));
}
