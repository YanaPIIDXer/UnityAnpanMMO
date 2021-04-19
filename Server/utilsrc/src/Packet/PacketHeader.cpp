#include "Packet/PacketHeader.h"

namespace YanaPOnlineUtil
{
	namespace Packet
	{

		const unsigned int CPacketHeader::HeaderSize = 3;

		// �R���X�g���N�^
		CPacketHeader::CPacketHeader()
			: PacketId(0), Size(0)
		{
		}

		// �R���X�g���N�^
		CPacketHeader::CPacketHeader(unsigned char InPacketId, unsigned short InSize)
			: PacketId(InPacketId), Size(InSize)
		{
		}

		// �V���A���C�Y
		bool CPacketHeader::Serialize(Stream::IMemoryStream *pStream)
		{
			if (!pStream->Serialize(&PacketId))
			{
				return false;
			}
			if (!pStream->Serialize(&Size))
			{
				return false;
			}

			return true;
		}

	}
}
