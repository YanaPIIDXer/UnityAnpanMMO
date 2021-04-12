using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PacketLogInRequest : YanaPOnlineUtil.Packet.Packet
	{

		public override byte PacketId { get { return (byte)PacketID.LogInRequest; } }

		

		

		public PacketLogInRequest()
		{
		}

		

		public override bool Serialize(IMemoryStream Stream)
{
			
			return true;
}
	}
}
