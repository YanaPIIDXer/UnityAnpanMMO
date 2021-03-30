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
 * @brief MySQLクエリクラス
 * @detail CMySqlConnectionクラスが生成する。
 */
class CMySqlQuery
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] pInConnection 接続オブジェクト
	 * @param[in] pInQuery クエリ
	 */
	CMySqlQuery(MYSQL *pInConnection, const char *pInQuery)
		: pConnection(pInConnection)
		, pQuery(pInQuery)
		, pStatement(NULL)
	{
	}

	/**
	 * @brief デストラクタ
	 */
	~CMySqlQuery()
	{
		Close();
	}

	/**
	 * @fn void BindInt(int *pPtr)
	 * @brief int型のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindInt(int *pPtr)
	{
		Binds.AddInt(pPtr);
	}

	/**
	 * @fn void BindInt(unsigned int *pPtr)
	 * @brief unsigned int型のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindInt(unsigned int *pPtr)
	{
		Binds.AddInt(pPtr);
	}

	/**
	 * @fn void BindShort(short *pPtr)
	 * @brief short型のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindShort(short *pPtr)
	{
		Binds.AddShort(pPtr);
	}

	/**
	 * @fn void BindShort(unsigned short *pPtr)
	 * @brief unsigned short型のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindShort(unsigned short *pPtr)
	{
		Binds.AddShort(pPtr);
	}

	/**
	 * @fn void BindChar(char *pPtr)
	 * @brief char型のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindChar(char *pPtr)
	{
		Binds.AddChar(pPtr);
	}

	/**
	 * @fn void BindChar(unsigned char *pPtr)
	 * @brief unsigned char型のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindChar(unsigned char *pPtr)
	{
		Binds.AddChar(pPtr);
	}

	/**
	 * @fn void BindFloat(float *pPtr)
	 * @brief float型のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindFloat(float *pPtr)
	{
		Binds.AddFloat(pPtr);
	}

	/**
	 * @fn void BindString(char *pPtr)
	 * @brief 文字列のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindString(char *pPtr)
	{
		Binds.AddString(pPtr, false);
	}

	/**
	 * @fn void BindWString(wchar_t *pPtr)
	 * @brief ワイド文字列のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindWString(wchar_t *pPtr)
	{
		Binds.AddWString(pPtr, false);
	}

	/**
	 * @fn void BindTime(MYSQL_TIME *pPtr)
	 * @brief 時間のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindTime(MYSQL_TIME *pPtr)
	{
		Binds.AddTime(pPtr);
	}

	/**
	 * @fn void BindResultInt(int *pPtr)
	 * @brief 結果のint型のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindResultInt(int *pPtr)
	{
		Results.AddInt(pPtr);
	}

	/**
	 * @fn void BindResultInt(unsigned int *pPtr)
	 * @brief 結果のunsigned int型のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindResultInt(unsigned int *pPtr)
	{
		Results.AddInt(pPtr);
	}

	/**
	 * @fn void BindResultShort(short *pPtr)
	 * @brief 結果のshort型のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindResultShort(short *pPtr)
	{
		Results.AddShort(pPtr);
	}

	/**
	 * @fn void BindResultShort(unsigned short *pPtr)
	 * @brief 結果のunsigned short型のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindResultShort(unsigned short *pPtr)
	{
		Results.AddShort(pPtr);
	}

	/**
	 * @fn void BindResultChar(char *pPtr)
	 * @brief 結果のchar型のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindResultChar(char *pPtr)
	{
		Results.AddChar(pPtr);
	}

	/**
	 * @fn void BindResultChar(unsigned char *pPtr)
	 * @brief 結果のunsigned char型のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindResultChar(unsigned char *pPtr)
	{
		Results.AddChar(pPtr);
	}

	/**
	 * @fn void BindResultFloat(float *pPtr)
	 * @brief 結果のfloat型のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindResultFloat(float *pPtr)
	{
		Results.AddFloat(pPtr);
	}

	/**
	 * @fn void BindResultString(char *pPtr)
	 * @brief 結果の文字列のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindResultString(char *pPtr)
	{
		Results.AddString(pPtr, true);
	}

	/**
	 * @fn void BindResultWString(wchar_t *pPtr)
	 * @brief 結果のワイド文字列のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindResultWString(wchar_t *pPtr)
	{
		Results.AddWString(pPtr, true);
	}

	/**
	 * @fn void BindResultTime(MYSQL_TIME *pPtr)
	 * @brief 結果の時間のバインド
	 * @param[in] pPtr 変数へのポインタ
	 */
	void BindResultTime(MYSQL_TIME *pPtr)
	{
		Results.AddTime(pPtr);
	}

	/**
	 * @fn bool ExecuteQuery()
	 * @brief クエリ実行
	 * @return 成功したらtrueを返す
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
	 * @brief フェッチ
	 * @return 次の結果が残っていればtrueを返す
	 */
	bool Fetch()
	{
		if (pStatement == NULL) { return false; }

		int Result = mysql_stmt_fetch(pStatement);
		return (Result == 0 || Result == MYSQL_DATA_TRUNCATED);
	}

	// 閉じる
	void Close()
	{
		if (pStatement == NULL) { return; }

		mysql_stmt_close(pStatement);
		pStatement = NULL;
	}

private:

	// MYSQLへの接続.
	MYSQL *pConnection;

	// クエリ
	const char *pQuery;

	// ステートメント
	MYSQL_STMT *pStatement;

	// バインド
	CMySqlBinds Binds;

	// 結果バインド
	CMySqlBinds Results;

};

}
}

#endif		// #if USE_MYSQL

#endif		// #ifndef __MYSQLQUERY_H__
