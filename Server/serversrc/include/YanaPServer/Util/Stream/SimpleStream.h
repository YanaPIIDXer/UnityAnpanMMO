#ifndef __SIMPLESTREAM_H__
#define __SIMPLESTREAM_H__

namespace YanaPServer
{
namespace Util
{
namespace Stream
{

/**
 * @class CSimpleStream
 * @brief �P���ȃX�g���[��
 * @detail Append���邽�тɓ�����new��delete������̂Œ��ӁB
 */
class CSimpleStream
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	CSimpleStream();

	/**
	 * @brief �f�X�g���N�^
	 */
	~CSimpleStream();

	/**
	 * @fn void AppendString(const char *pStr)
	 * @brief ������ǉ�
	 * @param[in] pStr �ǉ����镶����
	 */
	void AppendString(const char *pStr);

	/**
	 * @fn void AppendLine(const char *pStr)
	 * @brief �����ɉ��s�R�[�h��t�����ĕ�����ǉ�
	 * @param[in] pStr �ǉ����镶����
	 */
	void AppendStringLine(const char *pStr);

	/**
	 * @fn void AppendBinary(const char *pData, unsigned int Size)
	 * @brief �o�C�i���ǉ�
	 * @param[in] pData �f�[�^
	 * @param[in] Size �f�[�^��
	 */
	void AppendBinary(const char *pData, unsigned int Size);

	/**
	 * @fn const char *GetBuffer() const
	 * @brief ������擾
	 * @return ������
	 */
	const char *Get() const { return pBuffer; }

	/**
	 * @fn unsigned int GetLength() const
	 * @brief �����񒷎擾
	 * @return ������
	 */
	unsigned int GetLength() const { return Length; }

private:

	// �o�b�t�@
	char *pBuffer;

	// ������.
	unsigned int Length;

};

}
}
}

#endif		// #ifndef __SIMPLESTREAM_H__
