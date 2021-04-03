/**
 * @file $FILE_NAME$
 * @brief $CLASS_COMMENT$
 * @author NativePacketGenerator
 */

#ifndef $INCLUDE_GUARD$
#define $INCLUDE_GUARD$

#include "YanaPOnlineUtil/Packet/Packet.h"
#include "YanaPOnlineUtil/Stream/MemoryStream.h"
#include "type.h"
$INCLUDES$

using namespace YanaPOnlineUtil::Packet;
using namespace YanaPOnlineUtil::Stream;

/**
 * @brief $CLASS_COMMENT$
 */
class $CLASS_NAME$ $BASE_CLASS_NAME$
{

public:
	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	$GET_PACKET_ID_FUNCTION$

	$ENUMS$

	$MEMBERS$

	/**
	 * @brief �R���X�g���N�^
	 */
	$CLASS_NAME$()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	$CONSTRUCTOR$

	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(IMemoryStream *pStream)
	{
		$SERIALIZE_MEMBERS$
		return true;
	}
};

#endif // #ifndef $INCLUDE_GUARD$
