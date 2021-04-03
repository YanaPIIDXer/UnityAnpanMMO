#include "Stream/MemorySizeCaliculator.h"
#include <string.h>

namespace YanaPOnlineUtil
{
namespace Stream
{

// �R���X�g���N�^
CMemorySizeCaliculator::CMemorySizeCaliculator()
	: Size(0)
{
}

// int�̃V���A���C�Y
bool CMemorySizeCaliculator::Serialize(int *pData)
{
	Size += sizeof(int);
	return true;
}

// unsigned int�̃V���A���C�Y
bool CMemorySizeCaliculator::Serialize(unsigned int *pData)
{
	Size += sizeof(unsigned int);
	return true;
}

// short�̃V���A���C�Y
bool CMemorySizeCaliculator::Serialize(short *pData)
{
	Size += sizeof(short);
	return true;
}

// unsigned short�̃V���A���C�Y
bool CMemorySizeCaliculator::Serialize(unsigned short *pData)
{
	Size += sizeof(unsigned short);
	return true;
}

// char�̃V���A���C�Y
bool CMemorySizeCaliculator::Serialize(char *pData)
{
	Size += sizeof(char);
	return true;
}

// unsigned char�̃V���A���C�Y
bool CMemorySizeCaliculator::Serialize(unsigned char *pData)
{
	Size += sizeof(unsigned char);
	return true;
}

// float�̃V���A���C�Y
bool CMemorySizeCaliculator::Serialize(float *pData)
{
	Size += sizeof(float);
	return true;
}

// ������̃V���A���C�Y
bool CMemorySizeCaliculator::Serialize(std::string *pData)
{
	Size += sizeof(unsigned int);	// ������.
	Size += pData->length();		// ������.
	return true;
}

}
}
