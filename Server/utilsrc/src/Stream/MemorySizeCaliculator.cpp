#include "Stream/MemorySizeCaliculator.h"
#include <string.h>

namespace YanaPOnlineUtil
{
namespace Stream
{

// コンストラクタ
CMemorySizeCaliculator::CMemorySizeCaliculator()
	: Size(0)
{
}

// intのシリアライズ
bool CMemorySizeCaliculator::Serialize(int *pData)
{
	Size += sizeof(int);
	return true;
}

// unsigned intのシリアライズ
bool CMemorySizeCaliculator::Serialize(unsigned int *pData)
{
	Size += sizeof(unsigned int);
	return true;
}

// shortのシリアライズ
bool CMemorySizeCaliculator::Serialize(short *pData)
{
	Size += sizeof(short);
	return true;
}

// unsigned shortのシリアライズ
bool CMemorySizeCaliculator::Serialize(unsigned short *pData)
{
	Size += sizeof(unsigned short);
	return true;
}

// charのシリアライズ
bool CMemorySizeCaliculator::Serialize(char *pData)
{
	Size += sizeof(char);
	return true;
}

// unsigned charのシリアライズ
bool CMemorySizeCaliculator::Serialize(unsigned char *pData)
{
	Size += sizeof(unsigned char);
	return true;
}

// floatのシリアライズ
bool CMemorySizeCaliculator::Serialize(float *pData)
{
	Size += sizeof(float);
	return true;
}

// 文字列のシリアライズ
bool CMemorySizeCaliculator::Serialize(std::string *pData)
{
	Size += sizeof(unsigned int);	// 文字列長.
	Size += pData->length();		// 文字数.
	return true;
}

}
}
