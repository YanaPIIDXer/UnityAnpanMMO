#ifndef __RANDOMSTRING_H__
#define __RANDOMSTRING_H__

namespace YanaPServer
{
namespace Util
{

/**
 * @class CRandomString
 * @brief �����_��������
 */
class CRandomString
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	CRandomString();

	/**
	 * @brief �f�X�g���N�^
	 */
	~CRandomString();

	/**
	 * @fn void Generate(unsigned int Length)
	 * @brief ����
	 * @param[in] Length ������
	 * @param[in] bIsHex �P�U�i���̕����񂩁H
	 */
	void Generate(unsigned int Length, bool bIsHex = false);

	/**
	 * @fn const char *Get() const
	 * @brief �擾
	 * @return �������ꂽ�����_��������
	 */
	const char *Get() const { return pStr; }

private:

	// �����Z�b�g
	static const char *pCharSet;

	// ������
	char *pStr;

};

}
}

#endif		// #ifndef __RANDOMSTRING_H__
