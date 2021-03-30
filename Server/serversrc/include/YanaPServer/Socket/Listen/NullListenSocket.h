#ifndef __NULLLISTENSOCKET_H__
#define __NULLLISTENSOCKET_H__

#include "ListenSocket.h"

namespace YanaPServer
{
namespace Socket
{
class ISocket;

namespace Listen
{

/**
 * @class CNullListenSocket
 * @brief �������Ȃ�ListenSocket�N���X
 *		  ����`�̃v���b�g�t�H�[���Ŏg�p����B
 */
class CNullListenSocket : public IListenSocket
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	CNullListenSocket() {}

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~CNullListenSocket() {}

	/**
	 * @fn virtual void Poll() override
	 * @brief ���t���[���Ăяo������
	 */
	virtual void Poll() override {}

	/**
	 * @fn virtual bool Init() override
	 * @brief �\�P�b�g�̏�����
	 * @return �������Ȃ��̂ŏ��false��Ԃ��B
	 */
	virtual bool Init() override { return false; }

	/**
	 * @fn virtual bool Bind(unsigned int Port) override
	 * @brief �o�C���h
	 * @param[in] Port �|�[�g
	 * @return �������Ȃ��̂ŏ��false��Ԃ��B
	 */
	virtual bool Bind(unsigned int Port) override { return false; }

	/**
	 * @fn virtual bool Listen() override
	 * @brief ���b�X���J�n
	 * @return �������Ȃ��̂ŏ��false��Ԃ��B
	 */
	virtual bool Listen() override { return false; }

	/**
	 * @fn virtual void SetAcceptCallback(std::function<void(ISocket *)> &Callback) override
	 * @brief Accept���̃R�[���o�b�N��ݒ�
	 * @param[in] Callback Accept���ɌĂяo�����R�[���o�b�N
	 */
	virtual void SetAcceptCallback(const std::function<void(ISocket *)> &Callback) override {}

};

}
}
}

#endif		// #ifndef __NULLLISTENSOCKET_H__
