using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PacketPlayerPositionChange : YanaPOnlineUtil.Packet.Packet
	{

		public override byte PacketId { get { return (byte)PacketID.PlayerPositionChange; } }

		

		//! 座標
	public PositionPack Position = new PositionPack();
	

		public PacketPlayerPositionChange()
		{
		}

		public PacketPlayerPositionChange(PositionPack InPosition)
	{
		Position = InPosition;
		
	}

		public override bool Serialize(IMemoryStream Stream)
{
			if (!Position.Serialize(Stream)) { return false; }
		
			return true;
}
	}
}
