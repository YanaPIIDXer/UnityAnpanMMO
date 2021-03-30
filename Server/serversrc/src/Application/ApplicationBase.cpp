#include "Application/ApplicationBase.h"

namespace YanaPServer
{
namespace Application
{

// コンストラクタ
CApplicationBase::CApplicationBase(const std::function<void(PeerPtr)> &OnConnectFunction)
	: OnConnect(OnConnectFunction)
	, pListenSocket()
{
}

// デストラクタ
CApplicationBase::~CApplicationBase()
{
	Peers.clear();
}

// Listen開始.
bool CApplicationBase::StartListen(unsigned int Port)
{
	pListenSocket = YanaPServer::Socket::Listen::CListenSocket::Build(Port,
		std::bind(&CApplicationBase::OnListen, this, std::placeholders::_1));

	return (pListenSocket.get() != nullptr);
}

// 毎フレームの処理.
bool CApplicationBase::Service()
{
	if (pListenSocket)
	{
		pListenSocket->Poll();
	}

	PeerList::iterator It = Peers.begin();
	while (It != Peers.end())
	{
		if (!(*It)->IsValid())
		{
			It = Peers.erase(It);
		}
		else
		{
			(*It)->Poll();
			++It;
		}
	}

	return Update();
}


// Listenした。
void CApplicationBase::OnListen(YanaPServer::Socket::ISocket *pSocket)
{
	YanaPServer::Peer::CPeerBase *pPeer = CreatePeer(pSocket);
	if (pPeer == nullptr) { return; }

	PeerSharedPtr pSharedPeer = PeerSharedPtr(pPeer);
	Peers.push_back(pSharedPeer);

	OnConnect(pSharedPeer);
}

}
}