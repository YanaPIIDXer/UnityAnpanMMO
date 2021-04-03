#include "Packet/PacketHeader.h"

namespace YanaPOnlineUtil
{
namespace Packet
{

const unsigned int CPacketHeader::HeaderSize = 2;

// コンストラクタ
CPacketHeader::CPacketHeader()
	: PacketId(0)
	, Size(0)
{
}

// コンストラクタ
CPacketHeader::CPacketHeader(unsigned char InPacketId, unsigned char InSize)
	: PacketId(InPacketId)
	, Size(InSize)
{
}

// シリアライズ
bool CPacketHeader::Serialize(Stream::IMemoryStream *pStream)
{
	if (!pStream->Serialize(&PacketId)) { return false; }
	if (!pStream->Serialize(&Size)) { return false; }

	return true;
}

}
}
