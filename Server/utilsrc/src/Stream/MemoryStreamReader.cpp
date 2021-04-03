#include "Stream/MemoryStreamReader.h"
#include "EndianConverter.h"
#include <memory.h>

namespace YanaPOnlineUtil
{
namespace Stream
{

// �R���X�g���N�^
CMemoryStreamReader::CMemoryStreamReader(const char *pInBuffer, unsigned int InBufferSize)
	: pBuffer(nullptr)
	, BufferSize(InBufferSize)
	, CurrentPosition(0)
	, bIsError(false)
{
	pBuffer = new char[BufferSize];
	memcpy(pBuffer, pInBuffer, BufferSize);
}

// �f�X�g���N�^
CMemoryStreamReader::~CMemoryStreamReader()
{
	delete[] pBuffer;
}

// int�̃V���A���C�Y
bool CMemoryStreamReader::Serialize(int *pData)
{
	if (!Read(pData, sizeof(int))) { return false; }
	*pData = CEndianConverter::Convert(*pData);
	return true;
}

// unsigned int�̃V���A���C�Y
bool CMemoryStreamReader::Serialize(unsigned int *pData)
{
	if (!Read(pData, sizeof(unsigned int))) { return false; }
	*pData = CEndianConverter::Convert(*pData);
	return true;
}

// short�̃V���A���C�Y
bool CMemoryStreamReader::Serialize(short *pData)
{
	if (!Read(pData, sizeof(short))) { return false; }
	*pData = CEndianConverter::Convert(*pData);
	return true;
}

// unsigned short�̃V���A���C�Y
bool CMemoryStreamReader::Serialize(unsigned short *pData)
{
	if (!Read(pData, sizeof(unsigned short))) { return false; }
	*pData = CEndianConverter::Convert(*pData);
	return true;
}

// char�̃V���A���C�Y
bool CMemoryStreamReader::Serialize(char *pData)
{
	return Read(pData, sizeof(char));
}

// unsigned char�̃V���A���C�Y
bool CMemoryStreamReader::Serialize(unsigned char *pData)
{
	return Read(pData, sizeof(unsigned char));
}

// float�̃V���A���C�Y
bool CMemoryStreamReader::Serialize(float *pData)
{
	if (!Read(pData, sizeof(float))) { return false; }
	*pData = CEndianConverter::Convert(*pData);
	return true;
}

// ������̃V���A���C�Y
bool CMemoryStreamReader::Serialize(std::string *pData)
{
	// ������.
	unsigned int Length = 0;
	if (!Serialize(&Length)) { return false; }

	// ������.
	char *pStr = new char[Length + 1];
	memset(pStr, 0, Length + 1);
	if (!Read(pStr, Length)) { return false; }

	*pData = pStr;
	return true;
}


// �ǂݍ���
bool CMemoryStreamReader::Read(void *pData, unsigned int Size)
{
	if (bIsError) { return false; }
	
	if (CurrentPosition + Size > BufferSize)
	{
		bIsError = true;
		return false;
	}

	memcpy(pData, (pBuffer + CurrentPosition), Size);
	CurrentPosition += Size;
	return true;
}

}
}
