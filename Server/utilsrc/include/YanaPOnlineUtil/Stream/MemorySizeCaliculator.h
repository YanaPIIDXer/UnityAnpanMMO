#ifndef __MEMORYSIZECALICULATOR_H__
#define __MEMORYSIZECALICULATOR_H__

#include "MemoryStream.h"
#include "../Serializable/Serializable.h"

namespace YanaPOnlineUtil
{
namespace Stream
{

/**
 * @class CMemorySizeCaliculator
 * @brief �T�C�Y�v�Z�X�g���[��
 */
class CMemorySizeCaliculator : public IMemoryStream
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	CMemorySizeCaliculator();

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~CMemorySizeCaliculator() {}

	/**
	 * @fn virtual bool Serialize(int *pData) override
	 * @brief int�̃V���A���C�Y
	 * @param[in] pData �f�[�^
	 * @return ����������true��Ԃ��B
	 */
	virtual bool Serialize(int *pData) override;

	/**
	 * @fn virtual bool Serialize(unsigned int *pData) override
	 * @brief unsigned int�̃V���A���C�Y
	 * @param[in] pData �f�[�^
	 * @return ����������true��Ԃ��B
	 */
	virtual bool Serialize(unsigned int *pData) override;

	/**
	 * @fn virtual bool Serialize(short *pData) override
	 * @brief short�̃V���A���C�Y
	 * @param[in] pData �f�[�^
	 * @return ����������true��Ԃ��B
	 */
	virtual bool Serialize(short *pData) override;

	/**
	 * @fn virtual bool Serialize(unsigned short *pData) override
	 * @brief unsigned short�̃V���A���C�Y
	 * @param[in] pData �f�[�^
	 * @return ����������true��Ԃ��B
	 */
	virtual bool Serialize(unsigned short *pData) override;

	/**
	 * @fn virtual bool Serialize(char *pData) override
	 * @brief char�̃V���A���C�Y
	 * @param[in] pData �f�[�^
	 * @return ����������true��Ԃ��B
	 */
	virtual bool Serialize(char *pData) override;

	/**
	 * @fn virtual bool Serialize(unsigned char *pData) override
	 * @brief unsigned char�̃V���A���C�Y
	 * @param[in] pData �f�[�^
	 * @return ����������true��Ԃ��B
	 */
	virtual bool Serialize(unsigned char *pData) override;

	/**
	 * @fn virtual bool Serialize(float *pData) override
	 * @brief float�̃V���A���C�Y
	 * @param[in] pData �f�[�^
	 * @return ����������true��Ԃ��B
	 */
	virtual bool Serialize(float *pData) override;

	/**
	 * @fn virtual bool Serialize(std::string *pData) override
	 * @brief ������̃V���A���C�Y
	 * @param[in] pData �f�[�^
	 * @return ����������true��Ԃ��B
	 */
	virtual bool Serialize(std::string *pData) override;

	/**
	 * @fn virtual bool Serialize(Serializable::ISerializable *pData) override
	 * @brief �V���A���C�Y�\�ȃI�u�W�F�N�g�̃V���A���C�Y
	 * @param[in] pData �f�[�^
	 * @return ����������true��Ԃ��B
	 */
	virtual bool Serialize(Serializable::ISerializable *pData) override { return pData->Serialize(this); }

	/**
	 * @fn virtual bool Serialize(void *pData, unsigned int DataSize) override
	 * @brief �C�ӂ̃f�[�^���V���A���C�Y
	 * @param[in] pData �f�[�^
	 * @param[in] DataSize �f�[�^��
	 * @return ����������true��Ԃ��B
	 */
	virtual bool Serialize(void *pData, unsigned int DataSize) override
	{
		Size += DataSize;
		return true;
	}

	/**
	 * @fn virtual bool IsError() const override
	 * @brief �G���[���������Ă��邩�H
	 * @return �G���[�Ȃ�Ė����̂ŏ��false��Ԃ��B
	 */
	virtual bool IsError() const override { return false; }

	/**
	 * @fn virtual bool IsLeftData() const override
	 * @brief �ǂݍ���ł��Ȃ��f�[�^���c���Ă��邩�H
	 * @return �ǂݍ��ރf�[�^�Ȃ�Ė����̂ŏ��false��Ԃ��B
	 */
	virtual bool IsLeftData() const override { return false; }

	/**
	 * @fn virtual EStreamType GetType() const override
	 * @brief �X�g���[���^�C�v���擾
	 * @return �X�g���[���^�C�v�Ԃ��B
	 */
	virtual EStreamType GetType() const override { return EStreamType::CalcSize; }

	/**
	 * @fn unsigned int GetSize() const
	 * @brief �T�C�Y�擾
	 * @return �T�C�Y
	 */
	unsigned int GetSize() const { return Size; }

private:

	// �T�C�Y
	unsigned int Size;

};

}
}

#endif		// #ifndef __MEMORYSIZECALICULATOR_H__
