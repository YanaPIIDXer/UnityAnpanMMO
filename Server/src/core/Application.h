#ifndef APPLICATION_H
#define APPLICATION_H

#include "YanaPServer/Application/ApplicationBase.h"
using namespace YanaPServer::Application;
#include "type.h"

namespace YanaPServer::Peer
{
    class CPeerBase;
}

// アプリケーションクラス
class Application : public CApplicationBase
{
public:
    // コンストラクタ
    Application();

    // デストラクタ
    virtual ~Application();

    // Peer生成
    virtual YanaPServer::Peer::CPeerBase *CreatePeer(YanaPServer::Socket::ISocket *pSocket) override;

protected:
private:
    // 次のPeerに割り振るID
    uint NextPeerId;
};

#endif // #ifndef APPLICATION_H
