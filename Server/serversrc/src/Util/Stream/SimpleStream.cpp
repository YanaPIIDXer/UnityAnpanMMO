#include "Util/Stream/SimpleStream.h"
#include <string.h>
#include <memory.h>

namespace YanaPServer
{
namespace Util
{
namespace Stream
{

// �R���X�g���N�^
CSimpleStream::CSimpleStream()
	: pBuffer(nullptr)
	, Length(0)
{
	pBuffer = new char[1];
	pBuffer[0] = '\0';
}

// �f�X�g���N�^
CSimpleStream::~CSimpleStream()
{
	delete[] pBuffer;
}

// ������ǉ�.
void CSimpleStream::AppendString(const char *pStr)
{
	size_t StrLength = strlen(pStr);
	int NewBufferSize = Length + StrLength + 1;
	char *pTmp = new char[NewBufferSize];
	memset(pTmp, 0, NewBufferSize);
	memcpy(pTmp, pBuffer, Length);

	delete[] pBuffer;
	pBuffer = pTmp;

	memcpy((pBuffer + Length), pStr, StrLength);
	Length += StrLength;
}

// �����ɉ��s��t�����Ēǉ�.
void CSimpleStream::AppendStringLine(const char *pStr)
{
	size_t StrLength = strlen(pStr);
	int NewBufferSize = Length + StrLength + 2;
	char *pTmp = new char[NewBufferSize];
	memset(pTmp, 0, NewBufferSize);
	memcpy(pTmp, pBuffer, Length);

	delete[] pBuffer;
	pBuffer = pTmp;

	memcpy((pBuffer + Length), pStr, StrLength);
	(*(pBuffer + Length + StrLength)) = '\n';
	Length += StrLength + 1;
}

// �����ɉ��s��t�����Ēǉ�.
void CSimpleStream::AppendBinary(const char *pData, unsigned int Size)
{
	int NewBufferSize = Length + Size;
	char *pTmp = new char[NewBufferSize];
	memset(pTmp, 0, NewBufferSize);
	memcpy(pTmp, pBuffer, Length);

	delete[] pBuffer;
	pBuffer = pTmp;

	memcpy((pBuffer + Length), pData, Size);
	Length += Size;
}

}
}
}
