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

// コンストラクタ
CPacketSerializer::CPacketSerializer(const RecvFunction &InRecvFunc, const SendFunction &InSendFunc)
	: RecvFunc(InRecvFunc)
	, SendFunc(InSendFunc)
{
}

// デストラクタ
CPacketSerializer::~CPacketSerializer()
{
}

// 受信した
void CPacketSerializer::OnRecv(const char *pData, unsigned int Size)
{
	// バッファにデータをブチ込む。
	Buffer.resize(Buffer.size() + Size);
	unsigned int Begin = Buffer.size();
	for (unsigned int i = 0; i < Size; i++)
	{
		Buffer[Begin + i] = pData[i];
	}

	// ヘッダのシリアライズ
	CMemoryStreamReader StreamReader(&Buffer[0], Buffer.size());
	CPacketHeader Header;
	if (!Header.Serialize(&StreamReader)) { return; }

	unsigned int PacketSize = CPacketHeader::HeaderSize + Header.GetSize();
	if (Buffer.size() < PacketSize) { return; }

	// 受信に成功していたらバッファから消去。
	for (unsigned int i = 0; i < PacketSize; i++)
	{
		Buffer.erase(Buffer.begin());
	}

	// 受信関数にパケットＩＤとストリームを投げる。
	RecvFunc(Header.GetPacketId(), &StreamReader);
}

// 送信.
void CPacketSerializer::Send(CPacket *pPacket)
{
	// パケットサイズ計算
	CMemorySizeCaliculator SizeCaliculator;
	SizeCaliculator.Serialize(pPacket);

	// シリアライズ本番
	CMemoryStreamWriter StreamWriter(SizeCaliculator.GetSize() + CPacketHeader::HeaderSize);

	// ヘッダ
	CPacketHeader Header(pPacket->GetPacketId(), SizeCaliculator.GetSize());
	StreamWriter.Serialize(&Header);

	// パケット
	StreamWriter.Serialize(pPacket);

	// 送信
	SendFunc(StreamWriter.GetBuffer(), StreamWriter.GetSize());
}

}
}
