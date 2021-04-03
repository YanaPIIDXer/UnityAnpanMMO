#include "Stream/MemoryStreamWriter.h"
#include <memory.h>
#include <string.h>
#include "EndianConverter.h"

namespace YanaPOnlineUtil
{
namespace Stream
{

// コンストラクタ
CMemoryStreamWriter::CMemoryStreamWriter(unsigned int InBufferSize)
	: pBuffer(nullptr)
	, BufferSize(InBufferSize)
	, CurrentPosition(0)
	, bIsError(false)
{
	pBuffer = new char[BufferSize];
}

// デストラクタ
CMemoryStreamWriter::~CMemoryStreamWriter()
{
	delete[] pBuffer;
}

// intのシリアライズ
bool CMemoryStreamWriter::Serialize(int *pData)
{
	int Data = CEndianConverter::Convert(*pData);
	return Write(&Data, sizeof(int));
}

// unsigned intのシリアライズ
bool CMemoryStreamWriter::Serialize(unsigned int *pData)
{
	unsigned int Data = CEndianConverter::Convert(*pData);
	return Write(&Data, sizeof(unsigned int));
}

// shortのシリアライズ
bool CMemoryStreamWriter::Serialize(short *pData)
{
	short Data = CEndianConverter::Convert(*pData);
	return Write(&Data, sizeof(short));
}

// unsigned shortのシリアライズ
bool CMemoryStreamWriter::Serialize(unsigned short *pData)
{
	unsigned short Data = CEndianConverter::Convert(*pData);
	return Write(&Data, sizeof(unsigned short));
}

// charのシリアライズ
bool CMemoryStreamWriter::Serialize(char *pData)
{
	return Write(pData, sizeof(char));
}

// unsigned charのシリアライズ
bool CMemoryStreamWriter::Serialize(unsigned char *pData)
{
	return Write(pData, sizeof(unsigned char));
}

// floatのシリアライズ
bool CMemoryStreamWriter::Serialize(float *pData)
{
	float Data = CEndianConverter::Convert(*pData);
	return Write(&Data, sizeof(float));
}

// 文字列のシリアライズ
bool CMemoryStreamWriter::Serialize(std::string *pData)
{
	// 文字列長.
	unsigned int Length = pData->length();
	if (!Serialize(&Length)) { return false; }

	// 文字列.
	return Write(pData->c_str(), Length);
}


// 書き込み
bool CMemoryStreamWriter::Write(const void *pData, unsigned int Size)
{
	if (CurrentPosition + Size > BufferSize)
	{
		// バッファサイズをオーバーしたらエラー
		bIsError = true;
		return false;
	}

	memcpy((pBuffer + CurrentPosition), pData, Size);
	CurrentPosition += Size;
	return true;
}

}
}
