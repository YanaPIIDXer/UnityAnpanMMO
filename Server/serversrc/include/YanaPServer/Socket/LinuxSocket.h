#ifndef __LINUXSOCKET_H__
#define __LINUXSOCKET_H__

#ifdef _LINUX

#include "Socket.h"
#include <netinet/in.h>

#define INVALID_SOCKET -1

namespace YanaPServer
{
namespace Socket
{

/**
 * @class CLinuxSocket
 * @brief Linux�ł̃\�P�b�g�̋�������������N���X
 */
class CLinuxSocket : public ISocket
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	CLinuxSocket();

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] InSocket �\�P�b�g
	 */
	CLinuxSocket(int InSocket);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~CLinuxSocket();

	/**
	 * @fn virtual bool Connect(const char *pHost, unsigned int Port) override
	 * @brief �ڑ�
	 * @param[in] pHost �z�X�g
	 * @param[in] Port �|�[�g
	 * @return ����������true��Ԃ��B
	 */
	virtual bool Connect(const char *pHost, unsigned int Port) override;

	/**
	 * @fn virtual bool PollConnect() override
	 * @brief �ڑ������܂Ŗ��t���[�����s����鏈��
	 * @return �ڑ��ɐ���������true��Ԃ��B
	 */
	virtual bool PollConnect() override;

	/**
	 * @fn virtual bool IsValid() const override
	 * @brief �L�����H
	 * @return �L���Ȃ�true��Ԃ��B
	 */
	virtual bool IsValid() const override { return (Socket != INVALID_SOCKET); }

	/**
	 * @fn virtual bool Send(const char *pData, unsigned int Size) override
	 * @brief ���M
	 * @param[in] pData �f�[�^
	 * @param[in] Size ���M�T�C�Y
	 * @return ���M�o�C�g����Ԃ��B���s����-1��Ԃ��B
	 */
	virtual int Send(const char *pData, unsigned int Size) override;

	/**
	 * @fn virtual int Recv(char *pBuffer, unsigned int BufferSize) override
	 * @brief ��M
	 * @param[in] pBuffer �o�b�t�@
	 * @param[in] BufferSize �o�b�t�@�T�C�Y
	 * @return ��M�o�C�g����Ԃ��B���s����-1��Ԃ��B
	 */
	virtual int Recv(char *pBuffer, unsigned int BufferSize) override;

private:

	// �\�P�b�g
	int Socket;

	// �m���u���b�L���O���[�h
	u_long NonBlockingMode;

	// �ڑ���A�h���X
	sockaddr_in ConnectAddr;

};

}
}

#endif		// #ifdef _LINUX

#endif		// #ifndef __LINUXSOCKET_H__
