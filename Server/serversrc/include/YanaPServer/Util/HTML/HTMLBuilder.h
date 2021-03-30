#ifndef __HTMLBUILDER_H__
#define __HTMLBUILDER_H__

#include <string>
#include "HTMLObject.h"
#include <vector>

namespace YanaPServer
{
namespace Util
{
namespace HTML
{

/**
 * @class CHTMLBuilder
 * @brief �g�s�l�k�\�z�N���X
 */
class CHTMLBuilder
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] InTitle �y�[�W�̃^�C�g��
	 */
	CHTMLBuilder(const std::string &InTitle);

	/**
	 * @�f�X�g���N�^
	 */
	~CHTMLBuilder();

	/**
	 * @fn std::string Generate() const
	 * @brief �\�z
	 * @return �\�z���ꂽHTML
	 */
	std::string Generate() const;

	/**
	 * @fn void AddText(const std::string &Text, bool bAppendNewLine)
	 * @brief �e�L�X�g�ǉ�
	 * @param[in] Text�e�L�X�g
	 * @param[in] bAppendNewLine ���s���邩�H
	 * @return �e�L�X�g�I�u�W�F�N�g
	 */
	CHTMLText *AddText(const std::string &Text, bool bAppendNewLine = true);

	/**
	 * @fn void AddLink(const char *pURL, const char *pText, bool bAppendNewLine)
	 * @brief �����N�ǉ�
	 * @param[in] pURL URL
	 * @param[in] pText �e�L�X�g
	 * @param[in] bAppendNewLine ���s���邩�H
	 * @return �����N�I�u�W�F�N�g
	 */
	CHTMLLink *AddLink(const char *pURL, const char *pText, bool bAppendNewLine = true);

	/**
	 * @fn CHTMLForm *AddFormAsPOST(const char *pActionTarget)
	 * @brief POST���\�b�h�Ńt�H�[���ǉ�
	 * @param[in] pActionTarget �A�N�V�����^�[�Q�b�g
	 * @return �t�H�[���I�u�W�F�N�g�ւ̃|�C���^
	 */
	CHTMLForm *AddFormAsPOST(const char *pActionTarget)
	{
		return AddForm(CHTMLForm::EMethod::POST, pActionTarget);
	}

	/**
	 * @fn CHTMLForm *AddFormAsGET(const char *pActionTarget)
	 * @brief GET���\�b�h�Ńt�H�[���ǉ�
	 * @param[in] pActionTarget �A�N�V�����^�[�Q�b�g
	 * @return �t�H�[���I�u�W�F�N�g�ւ̃|�C���^
	 */
	CHTMLForm *AddFormAsGET(const char *pActionTarget)
	{
		return AddForm(CHTMLForm::EMethod::GET, pActionTarget);
	}

	/**
	 * @fn CHTMLTable *AddTable(int Border = 1)
	 * @brief �e�[�u���ǉ�
	 * @param[in] Border �{�[�_�[���C��
	 * @return �e�[�u���I�u�W�F�N�g
	 */
	CHTMLTable *AddTable(int Border = 1);

	/**
	 * @fn CHTMLStyle *AddStyle()
	 * @brief �X�^�C���ǉ�
	 * @return �X�^�C���I�u�W�F�N�g
	 */
	CHTMLStyle *AddStyle();

	/**
	 * @fn CHTMLScript *AddScript(const char *pScriptType = "text/javascript")
	 * @brief �X�N���v�g�ǉ�
	 * @param[in] pScriptType �X�N���v�g�̃^�C�v
	 * @return �X�N���v�g�I�u�W�F�N�g
	 */
	CHTMLScript *AddScript(const char *pScriptType = "text/javascript");

	/**
	 * @fn void AddHeaderObject(IHTMLObject)
	 * @brief �w�b�_�I�u�W�F�N�g�ǉ�
	 * @param[in] pObject �I�u�W�F�N�g
	 */
	void AddHeaderObject(IHTMLObject *pObject)
	{
		HTMLObjectSharedPtr pPtr(pObject);
		HeaderObjects.push_back(pPtr);
	}

	/**
	 * @fn void AddBodyObject(IHTMLObject)
	 * @brief �{�f�B�I�u�W�F�N�g�ǉ�
	 * @param[in] pObject �I�u�W�F�N�g
	 */
	void AddBodyObject(IHTMLObject *pObject)
	{
		HTMLObjectSharedPtr pPtr(pObject);
		BodyObjects.push_back(pPtr);
	}

private:

	// �y�[�W�̃^�C�g��
	std::string Title;

	// �w�b�_�I�u�W�F�N�g�Q.
	std::vector<HTMLObjectSharedPtr> HeaderObjects;

	// �{�f�B�I�u�W�F�N�g�Q.
	std::vector<HTMLObjectSharedPtr> BodyObjects;


	// �t�H�[���ǉ�.
	CHTMLForm *AddForm(CHTMLForm::EMethod Method, const char *pActionTarget);

};

}
}
}

#endif		// #ifndef __HTMLBUILDER_H__
