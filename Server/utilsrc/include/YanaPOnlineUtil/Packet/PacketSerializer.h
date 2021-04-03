#ifndef __PACKETSERIALIZER_H__
#define __PACKETSERIALIZER_H__

#include <functional>
#include "../Stream/MemoryStream.h"
#include <vector>

namespace YanaPOnlineUtil
{
namespace Packet
{

class CPacket;

/**
 * @class CPacketSerializer
 * @brief �p�P�b�g�V���A���C�Y�N���X
 */
class CPacketSerializer
{

private:		// �ʖ���`.

	typedef std::function<void(unsigned char, Stream::IMemoryStream *)> RecvFunction;
	typedef std::function<void(const char *, unsigned int)> SendFunction;

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] InRecvFunc ��M�֐�
	 * @param[in] InSendFunc ���M�֐�
	 */
	CPacketSerializer(const RecvFunction &InRecvFunc, const SendFunction &InSendFunc);

	/**
	 * @brief �f�X�g���N�^
	 */
	~CPacketSerializer();

	/**
	 * @fn void OnRecv(const char *pData, unsigned int Size)
	 * @brief ��M����
	 * @param[in] pData �f�[�^
	 * @param[in] Size �f�[�^�T�C�Y
	 */
	void OnRecv(const char *pData, unsigned int Size);

	/**
	 * @fn void Send(CPacket *pPacket)
	 * @brief ���M
	 * @param[in] ���M�p�P�b�g
	 */
	void Send(CPacket *pPacket);
		
private:

	// ��M�֐�.
	 RecvFunction RecvFunc;

	// ���M�֐�.
	 SendFunction SendFunc;

	 // �o�b�t�@
	 std::vector<char> Buffer;
};

}
}

#endif		// #ifndef __PACKETSERIALIZER_H__
