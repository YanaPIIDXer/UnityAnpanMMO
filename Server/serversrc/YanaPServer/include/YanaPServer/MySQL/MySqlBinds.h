#ifndef __MYSQLBINDS_H__
#define __MYSQLBINDS_H__

#if USE_MYSQL

#ifdef _WIN32
#include <windows.h>
#include <mysql.h>
#else
#include <mysql/mysql.h>
#endif

#include <vector>

namespace YanaPServer
{
namespace MySQL
{

#define STRING_BUFFER_LENGTH 256

/**
 * @class CMySqlBinds
 * @brief バインド
 * @detail 利用者がこのクラスを直接操作する事はない。
 *         （CMySqlQueryクラスを使用する。）
 */
class CMySqlBinds
{

public:

	/**
	 * @brief コンストラクタ
	 */
	CMySqlBinds()
		: pBinds(NULL)
		, Length(0)
	{
	}

	/**
	 * @brief デストラクタ
	 */
	~CMySqlBinds()
	{
		delete[] pBinds;
		pBinds = NULL;
	}

	/**
	 * @fn void AddInt(int *pPtr)
	 * @brief int追加
	 * @param[in] pPtr 変数へのポインタ
	 */
	void AddInt(int *pPtr)
	{
		MYSQL_BIND Bind;
		memset(&Bind, 0, sizeof(Bind));
		Bind.buffer_type = MYSQL_TYPE_LONG;
		Bind.buffer = pPtr;
		Bind.buffer_length = sizeof(*pPtr);
		Bind.is_null = 0;

		Reallocate();
		pBinds[Length - 1] = Bind;
	}

	/**
	 * @fn void AddInt(unsigned int *pPtr)
	 * @brief unsigned int追加
	 * @param[in] pPtr 変数へのポインタ
	 */
	void AddInt(unsigned int *pPtr)
	{
		MYSQL_BIND Bind;
		memset(&Bind, 0, sizeof(Bind));
		Bind.buffer_type = MYSQL_TYPE_LONG;
		Bind.is_unsigned = true;
		Bind.buffer = pPtr;
		Bind.buffer_length = sizeof(*pPtr);
		Bind.is_null = 0;

		Reallocate();
		pBinds[Length - 1] = Bind;
	}

	/**
	 * @fn void AddShort(short *pPtr)
	 * @brief short追加
	 * @param[in] pPtr 変数へのポインタ
	 */
	void AddShort(short *pPtr)
	{
		MYSQL_BIND Bind;
		memset(&Bind, 0, sizeof(Bind));
		Bind.buffer_type = MYSQL_TYPE_SHORT;
		Bind.buffer = pPtr;
		Bind.buffer_length = sizeof(*pPtr);
		Bind.is_null = 0;

		Reallocate();
		pBinds[Length - 1] = Bind;
	}

	/**
	 * @fn void AddShort(unsigned short *pPtr)
	 * @brief unsigned short追加
	 * @param[in] pPtr 変数へのポインタ
	 */
	void AddShort(unsigned short *pPtr)
	{
		MYSQL_BIND Bind;
		memset(&Bind, 0, sizeof(Bind));
		Bind.buffer_type = MYSQL_TYPE_SHORT;
		Bind.buffer = pPtr;
		Bind.buffer_length = sizeof(*pPtr);
		Bind.is_unsigned = true;
		Bind.is_null = 0;

		Reallocate();
		pBinds[Length - 1] = Bind;
	}

	/**
	 * @fn void AddChar(char *pPtr)
	 * @brief char追加
	 * @param[in] pPtr 変数へのポインタ
	 */
	void AddChar(char *pPtr)
	{
		MYSQL_BIND Bind;
		memset(&Bind, 0, sizeof(Bind));
		Bind.buffer_type = MYSQL_TYPE_TINY;
		Bind.buffer = pPtr;
		Bind.buffer_length = sizeof(*pPtr);
		Bind.is_null = 0;

		Reallocate();
		pBinds[Length - 1] = Bind;
	}

	/**
	 * @fn void AddChar(unsigned char *pPtr)
	 * @brief unsigned char追加
	 * @param[in] pPtr 変数へのポインタ
	 */
	void AddChar(unsigned char *pPtr)
	{
		MYSQL_BIND Bind;
		memset(&Bind, 0, sizeof(Bind));
		Bind.buffer_type = MYSQL_TYPE_TINY;
		Bind.buffer = pPtr;
		Bind.buffer_length = sizeof(*pPtr);
		Bind.is_unsigned = true;
		Bind.is_null = 0;

		Reallocate();
		pBinds[Length - 1] = Bind;
	}

	/**
	 * @fn void AddFloat(float *pPtr)
	 * @brief float追加
	 * @param[in] pPtr 変数へのポインタ
	 */
	void AddFloat(float *pPtr)
	{
		MYSQL_BIND Bind;
		memset(&Bind, 0, sizeof(Bind));
		Bind.buffer_type = MYSQL_TYPE_FLOAT;
		Bind.buffer = pPtr;
		Bind.buffer_length = sizeof(*pPtr);
		Bind.is_null = 0;

		Reallocate();
		pBinds[Length - 1] = Bind;
	}

	/**
	 * @fn void AddString(char *pPtr)
	 * @brief 文字列追加
	 * @param[in] pPtr 変数へのポインタ
	 * @param[in] bForResult 結果へのバインドか？
	 */
	void AddString(char *pPtr, bool bForResult)
	{
		MYSQL_BIND Bind;
		memset(&Bind, 0, sizeof(Bind));
		Bind.buffer_type = MYSQL_TYPE_STRING;
		Bind.buffer = pPtr;
		if (!bForResult)
		{
			Bind.buffer_length = strlen(pPtr);
		}
		else
		{
			Bind.buffer_length = STRING_BUFFER_LENGTH;
		}
		Bind.is_null = 0;

		Reallocate();
		pBinds[Length - 1] = Bind;
	}

	/**
	 * @fn void AddWString(wchar_t *pPtr)
	 * @brief ワイド文字列追加
	 * @param[in] pPtr 変数へのポインタ
	 * @param[in] bForResult 結果へのバインドか？
	 */
	void AddWString(wchar_t *pPtr, bool bForResult)
	{
		MYSQL_BIND Bind;
		memset(&Bind, 0, sizeof(Bind));
		Bind.buffer_type = MYSQL_TYPE_STRING;
		Bind.buffer = pPtr;
		if (!bForResult)
		{
			Bind.buffer_length = wcslen(pPtr);
		}
		else
		{
			Bind.buffer_length = STRING_BUFFER_LENGTH;
		}
		Bind.is_null = 0;

		Reallocate();
		pBinds[Length - 1] = Bind;
	}

	/**
	 * @fn void AddTime(MYSQL_TIME *pPtr)
	 * @brief 時間追加
	 * @param[in] pPtr 変数へのポインタ
	 */
	void AddTime(MYSQL_TIME *pPtr)
	{
		MYSQL_BIND Bind;
		memset(&Bind, 0, sizeof(Bind));
		Bind.buffer_type = MYSQL_TYPE_DATE;
		Bind.buffer = pPtr;
		Bind.buffer_length = sizeof(*pPtr);
		Bind.is_null = 0;

		Reallocate();
		pBinds[Length - 1] = Bind;
	}

	/**
	 * @fn MYSQL_BIND *Get() 
	 * @brief 取得
	 * @return バインドオブジェクト
	 */
	MYSQL_BIND *Get() { return pBinds; }

private:

	// バインド
	MYSQL_BIND *pBinds;

	// 配列長.
	int Length;

	// 領域拡張.
	void Reallocate()
	{
		MYSQL_BIND *pTmp = pBinds;
		Length++;
		pBinds = new MYSQL_BIND[Length];
		for (int i = 0; i < Length - 1; i++)
		{
			pBinds[i] = pTmp[i];
		}

		delete[] pTmp;
	}

};

}
}

#endif		// #if USE_MYSQL

#endif		// #ifndef __MYSQLBINDS_H__
