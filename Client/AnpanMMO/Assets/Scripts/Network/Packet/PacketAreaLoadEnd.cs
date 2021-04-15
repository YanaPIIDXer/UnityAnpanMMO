using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PacketAreaLoadEnd : YanaPOnlineUtil.Packet.Packet
	{

		public override byte PacketId { get { return (byte)PacketID.AreaLoadEnd; } }

		

		

		public PacketAreaLoadEnd()
		{
		}

		

		public override bool Serialize(IMemoryStream Stream)
{
			
			return true;
}
	}
}
