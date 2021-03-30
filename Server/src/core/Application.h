#ifndef APPLICATION_H
#define APPLICATION_H

#include "YanaPServer/Application/ApplicationBase.h"
using namespace YanaPServer::Application;

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
};

#endif // #ifndef APPLICATION_H
