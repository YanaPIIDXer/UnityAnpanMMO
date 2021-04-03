#include "Stream/MemoryStreamWriter.h"
#include <memory.h>
#include <string.h>
#include "EndianConverter.h"

namespace YanaPOnlineUtil
{
namespace Stream
{

// �R���X�g���N�^
CMemoryStreamWriter::CMemoryStreamWriter(unsigned int InBufferSize)
	: pBuffer(nullptr)
	, BufferSize(InBufferSize)
	, CurrentPosition(0)
	, bIsError(false)
{
	pBuffer = new char[BufferSize];
}

// �f�X�g���N�^
CMemoryStreamWriter::~CMemoryStreamWriter()
{
	delete[] pBuffer;
}

// int�̃V���A���C�Y
bool CMemoryStreamWriter::Serialize(int *pData)
{
	int Data = CEndianConverter::Convert(*pData);
	return Write(&Data, sizeof(int));
}

// unsigned int�̃V���A���C�Y
bool CMemoryStreamWriter::Serialize(unsigned int *pData)
{
	unsigned int Data = CEndianConverter::Convert(*pData);
	return Write(&Data, sizeof(unsigned int));
}

// short�̃V���A���C�Y
bool CMemoryStreamWriter::Serialize(short *pData)
{
	short Data = CEndianConverter::Convert(*pData);
	return Write(&Data, sizeof(short));
}

// unsigned short�̃V���A���C�Y
bool CMemoryStreamWriter::Serialize(unsigned short *pData)
{
	unsigned short Data = CEndianConverter::Convert(*pData);
	return Write(&Data, sizeof(unsigned short));
}

// char�̃V���A���C�Y
bool CMemoryStreamWriter::Serialize(char *pData)
{
	return Write(pData, sizeof(char));
}

// unsigned char�̃V���A���C�Y
bool CMemoryStreamWriter::Serialize(unsigned char *pData)
{
	return Write(pData, sizeof(unsigned char));
}

// float�̃V���A���C�Y
bool CMemoryStreamWriter::Serialize(float *pData)
{
	float Data = CEndianConverter::Convert(*pData);
	return Write(&Data, sizeof(float));
}

// ������̃V���A���C�Y
bool CMemoryStreamWriter::Serialize(std::string *pData)
{
	// ������.
	unsigned int Length = pData->length();
	if (!Serialize(&Length)) { return false; }

	// ������.
	return Write(pData->c_str(), Length);
}


// ��������
bool CMemoryStreamWriter::Write(const void *pData, unsigned int Size)
{
	if (CurrentPosition + Size > BufferSize)
	{
		// �o�b�t�@�T�C�Y���I�[�o�[������G���[
		bIsError = true;
		return false;
	}

	memcpy((pBuffer + CurrentPosition), pData, Size);
	CurrentPosition += Size;
	return true;
}

}
}
