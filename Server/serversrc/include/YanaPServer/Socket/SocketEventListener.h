#ifndef __SOCKETEVENTLISTENER_H__
#define __SOCKETEVENTLISTENER_H__

namespace YanaPServer
{
namespace Socket
{

/**
 * @class ISocketEventListener
 * @brief �\�P�b�g�C�x���g���X�i
 */
class ISocketEventListener
{
public:

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~ISocketEventListener() {}

	/**
	 * @fn virtual void OnConnect() = 0
	 * @brief �ڑ����ꂽ
	 */
	virtual void OnConnect() = 0;

	/**
	 * @fn virtual void OnRecv(const char *pData, unsigned int Size) = 0
	 * @brief ��M����
	 * @param[in] pData �f�[�^
	 * @param[in] Size �f�[�^��
	 */
	virtual void OnRecv(const char *pData, unsigned int Size) = 0;

	/**
	 * @fn virtual void OnSend(unsigned int Size) = 0
	 * @brief ���M����
	 * @param[in] Size ���M�����f�[�^��
	 */
	virtual void OnSend(unsigned int Size) = 0;

	/**
	 * @fn virtual void OnDisconnect(ESocketDisconnectReason Reason) = 0
	 * @brief �ؒf���ꂽ
	 * @param[in] Reason �ؒf���R
	 */
	virtual void OnDisconnect(ESocketDisconnectReason Reason) = 0;

};

}
}
#endif		// #ifndef __SOCKETEVENTLISTENER_H__
