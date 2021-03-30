#ifndef __APPLICATIONBASE_H__
#define __APPLICATIONBASE_H__
#include "../Socket/Socket.h"
#include "../Peer/PeerBase.h"
#include "../Socket/Listen/ListenSocket.h"
#include <vector>
#include <memory>
#include <functional>

typedef std::weak_ptr<YanaPServer::Peer::CPeerBase> PeerPtr;

namespace YanaPServer
{
namespace Application
{

/**
 * @class CApplicationBase
 * @brief �A�v���P�[�V�������C�����N���X
 */
class CApplicationBase
{

private:		// �ʖ���`.

	typedef std::shared_ptr<YanaPServer::Peer::CPeerBase> PeerSharedPtr;
	typedef std::vector<PeerSharedPtr> PeerList;

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] OnConnectFunction �ڑ����R�[���o�b�N
	 */
	CApplicationBase(const std::function<void(PeerPtr)> &OnConnectFunction);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~CApplicationBase();

	/**
	 * @fn bool StartListen(unsigned int Port)
	 * @brief Listen�J�n
	 * @param[in] Port �ҋ@�|�[�g
	 * @return ����������true��Ԃ��B
	 */
	bool StartListen(unsigned int Port);

	/**
	 * @fn bool Service()
	 * @brief ���t���[���̏���
	 * @detail ���C���t���[���ŌĂяo�����B
	 * @return ���C�����[�v���I�����鎞��false��Ԃ��B
	 */
	bool Service();

protected:

	/**
	 * @fn virtual CPeerBase *CreatePeer(ISocket *pSocket) = 0
	 * @brief Peer����
	 * @param[in] pSocket �\�P�b�g
	 * @return CPeerBase��h�������I�u�W�F�N�g�𐶐����ĕԂ��B
	 */
	virtual YanaPServer::Peer::CPeerBase *CreatePeer(YanaPServer::Socket::ISocket *pSocket) = 0;

	/**
	 * @fn virtual bool Update()
	 * @brief �X�V����
	 * @return ���炩�̗v���Ń��C�����[�v�𔲂���ꍇ��false��Ԃ�
	 */
	virtual bool Update() { return true; }

private:

	// Peer���X�g
	PeerList Peers;

	// �ڑ����R�[���o�b�N
	std::function<void(PeerPtr)> OnConnect;

	// Listen�\�P�b�g
	YanaPServer::Socket::Listen::ListenSocketPtr pListenSocket;


	// Listen�����B
	void OnListen(YanaPServer::Socket::ISocket *pSocket);

};

}
}

#endif		// #ifndef __APPLICATIONBASE_H__
