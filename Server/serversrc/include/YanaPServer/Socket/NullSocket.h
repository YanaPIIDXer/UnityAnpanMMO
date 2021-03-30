#ifndef __NULLSOCKETBEHAVIOUR_H__
#define __NULLSOCKETBEHAVIOUR_H__

#include "Socket.h"

namespace YanaPServer
{
namespace Socket
{

/**
 * @class CNullSocket
 * @brief �������Ȃ�Socket
 *		  ����`�̃v���b�g�t�H�[���Ŏg�p�����B
 */
class CNullSocket : public ISocket
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	CNullSocket() {}

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~CNullSocket() {}

	/**
	 * @fn virtual boool PollConnect() override
	 * @brief �ڑ������܂Ŗ��t���[�����s����鏈��
	 * @return �������Ȃ��̂ŏ��false��Ԃ��B
	 */
	virtual bool PollConnect() override { return false; }

	/**
	 * @fn virtual bool Connect(const char *pHost, unsigned int Port) override
	 * @brief �ڑ�
	 * @param[in] pHost �z�X�g
	 * @param[in] Port �|�[�g
	 * @return �������Ȃ��̂ŏ��false��Ԃ��B
	 */
	virtual bool Connect(const char *pHost, unsigned int Port) override { return false; }

	/**
	 * @fn virtual bool IsValid() const override
	 * @brief �L�����H
	 * @return �L���ɂ͂Ȃ�Ȃ��̂ŏ��false��Ԃ��B
	 */
	virtual bool IsValid() const override { return false; }

	/**
	 * @fn virtual bool Send(const char *pData, unsigned int Size) override
	 * @brief ���M
	 * @param[in] pData �f�[�^
	 * @param[in] Size ���M�T�C�Y
	 * @return �������Ȃ��̂ŏ��-1��Ԃ��B
	 */
	virtual int Send(const char *pData, unsigned int Size) override { return false; }

	/**
	 * @fn virtual int Recv(char *pBuffer, unsigned int BufferSize) override
	 * @brief ��M
	 * @param[in] pBuffer �o�b�t�@
	 * @param[in] BufferSize �o�b�t�@�T�C�Y
	 * @return �������Ȃ��̂ŏ��-1��Ԃ��B
	 */
	virtual int Recv(char * pBuffer, unsigned int BufferSize) override { return -1; }

};

}
}

#endif		// #ifndef __NULLSOCKETBEHAVIOUR_H__
