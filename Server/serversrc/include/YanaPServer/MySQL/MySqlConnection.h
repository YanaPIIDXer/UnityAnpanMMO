#ifndef __MYSQLCONNECTION_H__
#define __MYSQLCONNECTION_H__

#if USE_MYSQL

#ifdef _WIN32
#include <windows.h>
#include <mysql.h>
#else
#include <mysql/mysql.h>
#endif

#include "MySqlQuery.h"

namespace YanaPServer
{
namespace MySQL
{

/**
 * @class CMySqlConnection
 * @brief MySQL�ڑ��N���X
 */
class CMySqlConnection
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	CMySqlConnection()
		: pConnection(NULL)
	{
	}

	/**
	 * @brief �f�X�g���N�^
	 */
	~CMySqlConnection()
	{
		Disconnect();
	}

	/**
	 * @fn bool Connect(const char *pHost, const char *pUserName, const char *pPassword, const char *pDBName)
	 * @brief �ڑ�
	 * @param[in] pHost �z�X�g
	 * @param[in] pUserName ���[�U��
	 * @param[in] pPassword �p�X���[�h
	 * @param[in] pDBName �c�a��
	 * @return ����������true��Ԃ�
	 */
	bool Connect(const char *pHost, const char *pUserName, const char *pPassword, const char *pDBName)
	{
		if (pConnection != NULL)
		{
			Disconnect();
		}

		pConnection = mysql_init(NULL);
		if (pConnection == NULL) { return false; }

		mysql_options(pConnection, MYSQL_SET_CHARSET_NAME, "utf8");

		if (!mysql_real_connect(pConnection, pHost, pUserName, pPassword, pDBName, 0, NULL, 0)) { return false; }

		return true;
	}

	/**
	 * @fn bool SimpleQuery(const char *pQuery) const
	 * @brief �P���ȃN�G�����s
	 * @param[in] pQuery �N�G��
	 * @return ����������true��Ԃ�
	 */
	bool SimpleQuery(const char *pQuery) const
	{
		if (pConnection == NULL) { return false; }

		int Result = mysql_query(pConnection, pQuery);
		return (Result == 0);
	}

	/**
	 * @fn CMySqlQuery CreateQuery(const char *pQuery) const
	 * @brief �N�G������
	 * @param[in] pQuery �N�G��
	 * @return �N�G���I�u�W�F�N�g
	 */
	CMySqlQuery CreateQuery(const char *pQuery) const
	{
		CMySqlQuery Query(pConnection, pQuery);
		return Query;
	}

	/**
	 * @fn void Disconnect()
	 * @brief �ؒf
	 */
	void Disconnect()
	{
		if (pConnection == NULL) { return; }

		mysql_close(pConnection);
		pConnection = NULL;
	}

private:

	// MySQL�ւ̐ڑ�.
	MYSQL *pConnection;

};

}
}

#endif		// #if USE_MYSQL

#endif		// #ifndef __MYSQLCONNECTION_H__
