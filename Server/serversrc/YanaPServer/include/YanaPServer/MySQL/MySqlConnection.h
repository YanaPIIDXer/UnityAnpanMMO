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
 * @brief MySQL接続クラス
 */
class CMySqlConnection
{

public:

	/**
	 * @brief コンストラクタ
	 */
	CMySqlConnection()
		: pConnection(NULL)
	{
	}

	/**
	 * @brief デストラクタ
	 */
	~CMySqlConnection()
	{
		Disconnect();
	}

	/**
	 * @fn bool Connect(const char *pHost, const char *pUserName, const char *pPassword, const char *pDBName)
	 * @brief 接続
	 * @param[in] pHost ホスト
	 * @param[in] pUserName ユーザ名
	 * @param[in] pPassword パスワード
	 * @param[in] pDBName ＤＢ名
	 * @return 成功したらtrueを返す
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
	 * @brief 単純なクエリ実行
	 * @param[in] pQuery クエリ
	 * @return 成功したらtrueを返す
	 */
	bool SimpleQuery(const char *pQuery) const
	{
		if (pConnection == NULL) { return false; }

		int Result = mysql_query(pConnection, pQuery);
		return (Result == 0);
	}

	/**
	 * @fn CMySqlQuery CreateQuery(const char *pQuery) const
	 * @brief クエリ生成
	 * @param[in] pQuery クエリ
	 * @return クエリオブジェクト
	 */
	CMySqlQuery CreateQuery(const char *pQuery) const
	{
		CMySqlQuery Query(pConnection, pQuery);
		return Query;
	}

	/**
	 * @fn void Disconnect()
	 * @brief 切断
	 */
	void Disconnect()
	{
		if (pConnection == NULL) { return; }

		mysql_close(pConnection);
		pConnection = NULL;
	}

private:

	// MySQLへの接続.
	MYSQL *pConnection;

};

}
}

#endif		// #if USE_MYSQL

#endif		// #ifndef __MYSQLCONNECTION_H__
