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
 * @brief �o�C���h
 * @detail ���p�҂����̃N���X�𒼐ڑ��삷�鎖�͂Ȃ��B
 *         �iCMySqlQuery�N���X���g�p����B�j
 */
class CMySqlBinds
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	CMySqlBinds()
		: pBinds(NULL)
		, Length(0)
	{
	}

	/**
	 * @brief �f�X�g���N�^
	 */
	~CMySqlBinds()
	{
		delete[] pBinds;
		pBinds = NULL;
	}

	/**
	 * @fn void AddInt(int *pPtr)
	 * @brief int�ǉ�
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
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
	 * @brief unsigned int�ǉ�
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
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
	 * @brief short�ǉ�
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
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
	 * @brief unsigned short�ǉ�
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
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
	 * @brief char�ǉ�
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
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
	 * @brief unsigned char�ǉ�
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
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
	 * @brief float�ǉ�
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
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
	 * @brief ������ǉ�
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 * @param[in] bForResult ���ʂւ̃o�C���h���H
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
	 * @brief ���C�h������ǉ�
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
	 * @param[in] bForResult ���ʂւ̃o�C���h���H
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
	 * @brief ���Ԓǉ�
	 * @param[in] pPtr �ϐ��ւ̃|�C���^
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
	 * @brief �擾
	 * @return �o�C���h�I�u�W�F�N�g
	 */
	MYSQL_BIND *Get() { return pBinds; }

private:

	// �o�C���h
	MYSQL_BIND *pBinds;

	// �z��.
	int Length;

	// �̈�g��.
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
