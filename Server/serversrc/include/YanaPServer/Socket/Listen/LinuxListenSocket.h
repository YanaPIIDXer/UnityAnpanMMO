#ifndef __LINUXLISTENSOCKET_H__
#define __LINUXLISTENSOCKET_H__

#ifdef _LINUX

#include "ListenSocket.h"

namespace YanaPServer
{
namespace Socket
{
namespace Listen
{

/**
 * @class CLinuxListenSocket
 * @brief Linux�pListen�\�P�b�g
 */
class CLinuxListenSocket : public IListenSocket
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	CLinuxListenSocket();

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~CLinuxListenSocket();

	/**
	 * @fn virtual void Poll() override
	 * @brief ���t���[���Ăяo������
	 */
	virtual void Poll() override;

	/**
	 * @fn virtual bool Init() override
	 * @brief �\�P�b�g�̏�����
	 * @return ����������true��Ԃ��B
	 */
	virtual bool Init() override;

	/**
	 * @fn virtual bool Bind(unsigned int Port) override
	 * @brief �o�C���h
	 * @param[in] Port �|�[�g
	 * @return ����������true��Ԃ��B
	 */
	virtual bool Bind(unsigned int Port) override;

	/**
	 * @fn virtual bool Listen() override
	 * @brief ���b�X���J�n
	 * @return ����ɊJ�n������true��Ԃ��B
	 */
	virtual bool Listen() override;

	/**
	 * @fn virtual void SetAcceptCallback(std::function<void(ISocket *)> &Callback) override
	 * @brief Accept���̃R�[���o�b�N��ݒ�
	 * @param[in] Callback Accept���ɌĂяo�����R�[���o�b�N
	 */
	virtual void SetAcceptCallback(const std::function<void(ISocket *)> &Callback) override { OnAccept = Callback; }

private:

	// �\�P�b�g
	int Socket;

	// �m���u���b�L���O���[�h
	u_long NonBlockingMode;

	// Accept���̃R�[���o�b�N
	std::function<void(ISocket *)> OnAccept;


	// ���.
	void Release();

};
}
}
}

#endif		// #ifdef _LINUX

#endif		// #ifndef __LINUXLISTENSOCKET_H__
