using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PacketLogIn : YanaPOnlineUtil.Packet.Packet
	{

		public override byte PacketId { get { return (byte)PacketID.LogIn; } }

		

		

		PacketLogIn()
		{
		}

		

		public override bool Serialize(IMemoryStream pStream)
		{
			
			return true;
		}
	}
}
