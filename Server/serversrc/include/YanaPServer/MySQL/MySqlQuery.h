#ifndef __MYSQLQUERY_H__
#define __MYSQLQUERY_H__

#if USE_MYSQL

#ifdef _WIN32
#include <windows.h>
#include <mysql.h>
#else
#include <mysql/mysql.h>
#endif

#include "MySqlBinds.h"

namespace YanaPServer
{
namespace MySQL
{

/**
 * @class CMySqlQuery
 * @brief MySQL�N�G���N���X
 * @detail CMySqlConnection�N���X����������B
 */
class CMySqlQuery
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] pInConnection �ڑ��I�u�W�F�N�g
	 * @param[in] pInQuery �N�G��
	 */
	CMySqlQuery(MYSQL *pInConnection, const char *pInQuery)
		: pConnection(pInConnection)
		, pQuery(pInQuery)
		, pStatement(NULL)
	{
	}

	/**
	 * @brief �f�X�g���N�^
	 */
	~CMySqlQuery()
	{
		Close();
	}

	/**
	 * @fn void BindInt(int *pPtr)
	 * @brief int�^�̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindInt(int *pPtr)
	{
		Binds.AddInt(pPtr);
	}

	/**
	 * @fn void BindInt(unsigned int *pPtr)
	 * @brief unsigned int�^�̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindInt(unsigned int *pPtr)
	{
		Binds.AddInt(pPtr);
	}

	/**
	 * @fn void BindShort(short *pPtr)
	 * @brief short�^�̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindShort(short *pPtr)
	{
		Binds.AddShort(pPtr);
	}

	/**
	 * @fn void BindShort(unsigned short *pPtr)
	 * @brief unsigned short�^�̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindShort(unsigned short *pPtr)
	{
		Binds.AddShort(pPtr);
	}

	/**
	 * @fn void BindChar(char *pPtr)
	 * @brief char�^�̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindChar(char *pPtr)
	{
		Binds.AddChar(pPtr);
	}

	/**
	 * @fn void BindChar(unsigned char *pPtr)
	 * @brief unsigned char�^�̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindChar(unsigned char *pPtr)
	{
		Binds.AddChar(pPtr);
	}

	/**
	 * @fn void BindFloat(float *pPtr)
	 * @brief float�^�̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindFloat(float *pPtr)
	{
		Binds.AddFloat(pPtr);
	}

	/**
	 * @fn void BindString(char *pPtr)
	 * @brief ������̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindString(char *pPtr)
	{
		Binds.AddString(pPtr, false);
	}

	/**
	 * @fn void BindWString(wchar_t *pPtr)
	 * @brief ���C�h������̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindWString(wchar_t *pPtr)
	{
		Binds.AddWString(pPtr, false);
	}

	/**
	 * @fn void BindTime(MYSQL_TIME *pPtr)
	 * @brief ���Ԃ̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindTime(MYSQL_TIME *pPtr)
	{
		Binds.AddTime(pPtr);
	}

	/**
	 * @fn void BindResultInt(int *pPtr)
	 * @brief ���ʂ�int�^�̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindResultInt(int *pPtr)
	{
		Results.AddInt(pPtr);
	}

	/**
	 * @fn void BindResultInt(unsigned int *pPtr)
	 * @brief ���ʂ�unsigned int�^�̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindResultInt(unsigned int *pPtr)
	{
		Results.AddInt(pPtr);
	}

	/**
	 * @fn void BindResultShort(short *pPtr)
	 * @brief ���ʂ�short�^�̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindResultShort(short *pPtr)
	{
		Results.AddShort(pPtr);
	}

	/**
	 * @fn void BindResultShort(unsigned short *pPtr)
	 * @brief ���ʂ�unsigned short�^�̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindResultShort(unsigned short *pPtr)
	{
		Results.AddShort(pPtr);
	}

	/**
	 * @fn void BindResultChar(char *pPtr)
	 * @brief ���ʂ�char�^�̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindResultChar(char *pPtr)
	{
		Results.AddChar(pPtr);
	}

	/**
	 * @fn void BindResultChar(unsigned char *pPtr)
	 * @brief ���ʂ�unsigned char�^�̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindResultChar(unsigned char *pPtr)
	{
		Results.AddChar(pPtr);
	}

	/**
	 * @fn void BindResultFloat(float *pPtr)
	 * @brief ���ʂ�float�^�̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindResultFloat(float *pPtr)
	{
		Results.AddFloat(pPtr);
	}

	/**
	 * @fn void BindResultString(char *pPtr)
	 * @brief ���ʂ̕�����̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindResultString(char *pPtr)
	{
		Results.AddString(pPtr, true);
	}

	/**
	 * @fn void BindResultWString(wchar_t *pPtr)
	 * @brief ���ʂ̃��C�h������̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindResultWString(wchar_t *pPtr)
	{
		Results.AddWString(pPtr, true);
	}

	/**
	 * @fn void BindResultTime(MYSQL_TIME *pPtr)
	 * @brief ���ʂ̎��Ԃ̃o�C���h
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 */
	void BindResultTime(MYSQL_TIME *pPtr)
	{
		Results.AddTime(pPtr);
	}

	/**
	 * @fn bool ExecuteQuery()
	 * @brief �N�G�����s
	 * @return ����������true��Ԃ�
	 */
	bool ExecuteQuery()
	{
		pStatement = mysql_stmt_init(pConnection);
		if (pStatement == NULL) { return false; }

		int Result = mysql_stmt_prepare(pStatement, pQuery, strlen(pQuery));
		if (Result != 0) { return false; }

		MYSQL_BIND *pBinds = Binds.Get();
		if (pBinds != NULL)
		{
			Result = mysql_stmt_bind_param(pStatement, pBinds);
			if (Result != 0) { return false; }
		}

		MYSQL_BIND *pResults = Results.Get();
		if (pResults != NULL)
		{
			Result = mysql_stmt_bind_result(pStatement, pResults);
			if (Result != 0) { return false; }
		}

		Result = mysql_stmt_execute(pStatement);
		if (Result != 0) { return false; }

		return true;
	}

	/**
	 * @fn bool Fetch()
	 * @brief �t�F�b�`
	 * @return ���̌��ʂ��c���Ă����true��Ԃ�
	 */
	bool Fetch()
	{
		if (pStatement == NULL) { return false; }

		int Result = mysql_stmt_fetch(pStatement);
		return (Result == 0 || Result == MYSQL_DATA_TRUNCATED);
	}

	// ����
	void Close()
	{
		if (pStatement == NULL) { return; }

		mysql_stmt_close(pStatement);
		pStatement = NULL;
	}

private:

	// MYSQL�ւ̐ڑ�.
	MYSQL *pConnection;

	// �N�G��
	const char *pQuery;

	// �X�e�[�g�����g
	MYSQL_STMT *pStatement;

	// �o�C���h
	CMySqlBinds Binds;

	// ���ʃo�C���h
	CMySqlBinds Results;

};

}
}

#endif		// #if USE_MYSQL

#endif		// #ifndef __MYSQLQUERY_H__
