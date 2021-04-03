using YanaPOnlineUtil.Packet;

namespace Network.Packet
{
    public class $CLASS_NAME$ : $BASE_CLASS_NAME$
	{

		$GET_PACKET_ID_FUNCTION$

		$ENUMS$

		$MEMBERS$

		$CLASS_NAME$()
		{
		}

		$CONSTRUCTOR$

		bool Serialize(MemoryStreamInterface* pStream)
{
					$SERIALIZE_MEMBERS$
					return true;
}
}