#ifndef __PACKETHEADER_H__
#define __PACKETHEADER_H__

#include "Serializable/Serializable.h"
#include "Packet.h"

namespace YanaPOnlineUtil
{
	namespace Packet
	{

		/**
 * @class CPacketHeader
 * @brief �p�P�b�g�w�b�_
 */
		class CPacketHeader : public Serializable::ISerializable
		{

		public:
			/**
	 * @brief �R���X�g���N�^
	 */
			CPacketHeader();

			/**
	 * @brief �R���X�g���N�^
	 * @param[in] InPacketId �p�P�b�g�h�c
	 * @param[in] InSize �T�C�Y
	 */
			CPacketHeader(unsigned char InPacketId, unsigned short InSize);

			/**
	 * @brief �f�X�g���N�^
	 */
			virtual ~CPacketHeader() {}

			/**
	 * @fn unsigned char GetPacketId() const
	 * @brief �p�P�b�g�h�c�擾
	 * @return �p�P�b�g�h�c
	 */
			unsigned char GetPacketId() const { return PacketId; }

			/**
	 * @fn unsigned char GetSize() const
	 * @brief �T�C�Y�擾
	 * @return �T�C�Y
	 */
			unsigned short GetSize() const { return Size; }

			/**
	 * @fn virtual bool Serialize(Util::Stream::IMemoryStream *pStream) override
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
			virtual bool Serialize(Stream::IMemoryStream *pStream) override;

			//! �w�b�_�T�C�Y
			static const unsigned int HeaderSize;

		private:
			// �p�P�b�g�h�c
			unsigned char PacketId;

			// �T�C�Y
			unsigned short Size;
		};

	}
}

#endif // #ifndef __PACKETHEADER_H__
