#ifndef __SOCKETBEHAVIOUR_H__
#define __SOCKETBEHAVIOUR_H__

#include <functional>
#include <vector>

namespace YanaPServer
{
namespace Socket
{

class ISocketEventListener;

/**
 * @enum ESocketDisconnectReason
 * @brief �\�P�b�g�ؒf���R
 */
enum class ESocketDisconnectReason
{
	//! �f�X�g���N�^��
	Destruct,

	//! ���M�G���[
	SendError,

	//! ��M�G���[
	RecvError,
};

/**
 * @class ISocket
 * @brief �\�P�b�g�̋������������邽�߂̃C���^�t�F�[�X
 */
class ISocket
{

public:

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~ISocket() {}

	/**
	 * @fn virtual bool Connect(const char *pHost, unsigned int Port) = 0
	 * @brief �ڑ�
	 * @param[in] pHost �z�X�g
	 * @param[in] Port �|�[�g
	 * @return ����������true��Ԃ��B
	 */
	virtual bool Connect(const char *pHost, unsigned int Port) = 0;

	/**
	 * @fn virtual boool PollConnect() = 0
	 * @brief �ڑ������܂Ŗ��t���[�����s����鏈��
	 * @return �ڑ��ɐ���������true��Ԃ��B
	 */
	virtual bool PollConnect() = 0;

	/**
	 * @fn virtual bool IsValid()
	 * @brief �L�����H
	 * @return �L���Ȃ�true��Ԃ��B
	 */
	virtual bool IsValid() const = 0;

	/**
	 * @fn virtual bool Send(const char *pData, unsigned int Size) = 0
	 * @brief ���M
	 * @param[in] pData �f�[�^
	 * @param[in] Size ���M�T�C�Y
	 * @return ���M�o�C�g����Ԃ��B���s����-1��Ԃ��B
	 */
	virtual int Send(const char *pData, unsigned int Size) = 0;

	/**
	 * @fn virtual int Recv(char *pBuffer, unsigned int BufferSize) = 0
	 * @brief ��M
	 * @param[in] pBuffer �o�b�t�@
	 * @param[in] BufferSize �o�b�t�@�T�C�Y
	 * @return ��M�o�C�g����Ԃ��B���s����-1��Ԃ��B
	 */
	virtual int Recv(char *pBuffer, unsigned int BufferSize) = 0;

};

/**
 * @class CSocket
 * @brief �\�P�b�g�N���X
 *        �e�v���b�g�t�H�[���ŋ��ʂ��镔���B
 */
class CSocket
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	CSocket();

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] pInSocket �\�P�b�g
	 */
	CSocket(ISocket *pInSocket);

	/**
	 * @brief �f�X�g���N�^
	 */
	~CSocket();

	/**
	 * @fn void SetEventListener()
	 * @brief �C�x���g���X�i���Z�b�g
	 * @param[in] pListener �C�x���g���X�i
	 */
	void SetEventListener(ISocketEventListener *pListener) { pEventListener = pListener; }

	/**
	 * @fn void Poll()
	 * @brief ���t���[�����s���鏈��
	 */
	void Poll();

	/**
	 * @fn bool Connect(const char *pHost, unsigned int Port)
	 * @brief �ڑ�
	 * @param[in] pHost �z�X�g
	 * @param[in] Port �|�[�g
	 * @return ����������true��Ԃ��B
	 */
	bool Connect(const char *pHost, unsigned int Port);

	/**
	 * @fn bool IsValid() const
	 * @brief �L�����H
	 * @return �L���Ȃ�true��Ԃ��B
	 */
	bool IsValid() const { return (pSocket != nullptr && pSocket->IsValid()); }

	/**
	 * @fn virtual bool Send(const char *pData, unsigned int Size) = 0
	 * @brief ���M
	 * @param[in] pData �f�[�^
	 * @param[in] Size ���M�T�C�Y
	 * @return ����������true��Ԃ��B
	 */
	bool Send(const char *pData, unsigned int Size);

	/**
	 * @fn void Release(ESocketDisconnectReason Reason)
	 * @brief ���
	 * @param[in] Reason �ؒf���R
	 */
	void Release(ESocketDisconnectReason Reason);

private:

	// State
	enum class EState
	{
		// �������Ă��Ȃ�
		None,

		// �ڑ���.
		Connecting,

		// �ڑ�����
		Connected,
	};

	// �\�P�b�g
	ISocket *pSocket;

	// �X�e�[�g
	EState State;

	// �f�[�^�L���[
	std::vector<char> DataQueue;

	// �C�x���g���X�i
	ISocketEventListener *pEventListener;


	// ���M����.
	void SendProc();

	// ��M����.
	void RecvProc();

};

}
}

#endif		// #ifndef __SOCKETBEHAVIOUR_H__
