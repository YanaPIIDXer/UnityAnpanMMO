#ifndef __LISTENSOCKET_H__
#define __LISTENSOCKET_H__

#include <functional>
#include <memory>

namespace YanaPServer
{
namespace Socket
{
class ISocket;

namespace Listen
{

/**
 * @class IListenSocket
 * @brief Listen�pSocket�C���^�t�F�[�X
 */
class IListenSocket
{

public:

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~IListenSocket() {}

	/**
	 * @fn virtual void Poll() = 0;
	 * @brief ���t���[���Ăяo������
	 */
	virtual void Poll() = 0;

	/**
	 * @fn virtual bool Init() = 0
	 * @brief �\�P�b�g�̏�����
	 * @return ����������true��Ԃ��B
	 */
	virtual bool Init() = 0;

	/**
	 * @fn virtual bool Bind(unsigned int Port) = 0
	 * @brief �o�C���h
	 * @param[in] Port �|�[�g
	 * @return ����������true��Ԃ��B
	 */
	virtual bool Bind(unsigned int Port) = 0;

	/**
	 * @fn virtual bool Listen() = 0
	 * @brief ���b�X���J�n
	 * @return ����ɊJ�n������true��Ԃ��B
	 */
	virtual bool Listen() = 0;

	/**
	 * @fn virtual void SetAcceptCallback(const std::function<void(ISocket *)> &Callback) = 0
	 * @brief Accept���̃R�[���o�b�N��ݒ�
	 * @param[in] Callback Accept���ɌĂяo�����R�[���o�b�N
	 */
	virtual void SetAcceptCallback(const std::function<void(ISocket *)> &Callback) = 0;

};

typedef std::unique_ptr<IListenSocket> ListenSocketPtr;

/**
 * @class CListenSocket
 * @brief Listen�pSocket�N���X
 */
class CListenSocket
{

public:

	/**
	 * @fn static void Build(unsigned int Port, std::function<void(ISocket *)> &AcceptCallback)
	 * @brief �\�z
	 * @param[in] Port �|�[�g
	 * @param[in] AcceptCallback Accept���̃R�[���o�b�N
	 * @return ����������true��Ԃ��B
	 */
	static ListenSocketPtr Build(unsigned int Port, const std::function<void(ISocket *)> &AcceptCallback);

private:

	// ListenSocket�I�u�W�F�N�g�𐶐��B
	static ListenSocketPtr Create();
	
};

}
}
}

#endif		// #ifndef __LISTENSOCKET_H__
