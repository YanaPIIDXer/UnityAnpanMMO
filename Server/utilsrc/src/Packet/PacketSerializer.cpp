#include "Packet/PacketSerializer.h"
#include "Packet/PacketHeader.h"
#include "Stream/MemoryStreamReader.h"
#include "Stream/MemorySizeCaliculator.h"
#include "Stream/MemoryStreamWriter.h"

using namespace YanaPOnlineUtil::Stream;

namespace YanaPOnlineUtil
{
namespace Packet
{

// �R���X�g���N�^
CPacketSerializer::CPacketSerializer(const RecvFunction &InRecvFunc, const SendFunction &InSendFunc)
	: RecvFunc(InRecvFunc)
	, SendFunc(InSendFunc)
{
}

// �f�X�g���N�^
CPacketSerializer::~CPacketSerializer()
{
}

// ��M����
void CPacketSerializer::OnRecv(const char *pData, unsigned int Size)
{
	// �o�b�t�@�Ƀf�[�^���u�`���ށB
	unsigned int Begin = Buffer.size();
	Buffer.resize(Buffer.size() + Size);
	for (unsigned int i = 0; i < Size; i++)
	{
		Buffer[Begin + i] = pData[i];
	}

	// �w�b�_�̃V���A���C�Y
	CMemoryStreamReader StreamReader(&Buffer[0], Buffer.size());
	CPacketHeader Header;
	if (!Header.Serialize(&StreamReader)) { return; }

	unsigned int PacketSize = CPacketHeader::HeaderSize + Header.GetSize();
	if (Buffer.size() < PacketSize) { return; }

	// ��M�ɐ������Ă�����o�b�t�@��������B
	for (unsigned int i = 0; i < PacketSize; i++)
	{
		Buffer.erase(Buffer.begin());
	}

	// ��M�֐��Ƀp�P�b�g�h�c�ƃX�g���[���𓊂���B
	RecvFunc(Header.GetPacketId(), &StreamReader);
}

// ���M.
void CPacketSerializer::Send(CPacket *pPacket)
{
	// �p�P�b�g�T�C�Y�v�Z
	CMemorySizeCaliculator SizeCaliculator;
	SizeCaliculator.Serialize(pPacket);

	// �V���A���C�Y�{��
	CMemoryStreamWriter StreamWriter(SizeCaliculator.GetSize() + CPacketHeader::HeaderSize);

	// �w�b�_
	CPacketHeader Header(pPacket->GetPacketId(), SizeCaliculator.GetSize());
	StreamWriter.Serialize(&Header);

	// �p�P�b�g
	StreamWriter.Serialize(pPacket);

	// ���M
	SendFunc(StreamWriter.GetBuffer(), StreamWriter.GetSize());
}

}
}
