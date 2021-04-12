using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class $CLASS_NAME$ : $BASE_CLASS_NAME$
	{

		$GET_PACKET_ID_FUNCTION$

		$ENUMS$

		$MEMBERS$

		public $CLASS_NAME$()
		{
		}

		$CONSTRUCTOR$

		public override bool Serialize(IMemoryStream Stream)
{
			$SERIALIZE_MEMBERS$
			return true;
}
	}
}
