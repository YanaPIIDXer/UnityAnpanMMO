using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PacketPlayerMove : YanaPOnlineUtil.Packet.Packet
	{

		public override byte PacketId { get { return (byte)PacketID.PlayerMove; } }

		

		//! 移動データ
	public PositionPack Position = new PositionPack();
	

		public PacketPlayerMove()
		{
		}

		public PacketPlayerMove(PositionPack InPosition)
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
