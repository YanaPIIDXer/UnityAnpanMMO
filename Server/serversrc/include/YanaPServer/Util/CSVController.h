#ifndef __CSVCONTROLLER_H__
#define __CSVCONTROLLER_H__

#include <vector>
#include <string>

namespace YanaPServer
{
namespace Util
{

typedef std::vector<std::string> Columns;

/**
 * @class CCSVController
 * @brief CSV����
 */
class CCSVController
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	CCSVController();

	/**
	 * @brief �f�X�g���N�^
	 */
	~CCSVController() {}

	/**
	 * @fn bool Load(const char *pFilePath)
	 * @brief �ǂݍ���
	 * @param[in] pFilePath �t�@�C���p�X
	 * @return ����������true��Ԃ�
	 */
	bool Load(const char *pFilePath);

	/**
	 * @fn bool Save(const char *pFilePath)
	 * @brief ��������
	 * @param[in] pFilePath �t�@�C���p�X
	 * @return ����������true��Ԃ�
	 */
	bool Save(const char *pFilePath);

	/**
	 * @fn bool GetRow(unsigned int Index, Columns &OutRow) const
	 * @brief �s�f�[�^���擾
	 * @param[in] Index �C���f�b�N�X
	 * @param[out] OutRow �s�f�[�^
	 * @return ����������true��Ԃ�
	 */
	bool GetRow(unsigned int Index, Columns &OutRow) const;

	/**
	 * @fn unsigned int GetRowCount() const
	 * @brief �s�����擾
	 * @return �s��
	 */
	unsigned int GetRowCount() const { return Rows.size(); }

	/**
	 * @fn void AddRow(const Columns &Row)
	 * @brief �s�f�[�^�𖖔��ɒǉ�
	 * @param[in] Row �s�f�[�^
	 */
	void AddRow(const Columns &Row);

	/**
	 * @fn void UpdateRow(unsigned int Index, const Columns &Row)
	 * @brief �s�f�[�^���X�V
	 * @param[in] Index �X�V����s�̃C���f�b�N�X
	 * @param[in] Row �s�f�[�^
	 */
	void UpdateRow(unsigned int Index, const Columns &Row);

private:

	// �s�f�[�^
	std::vector<Columns> Rows;


	// Split
	static void Split(const char *pData, const std::string &Delimiter, std::vector<std::string> &OutResult);

};

}
}

#endif		// #ifndef __CSVCONTROLLER_H__
