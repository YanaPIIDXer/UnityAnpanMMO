using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PacketPlayerMoved : YanaPOnlineUtil.Packet.Packet
	{

		public override byte PacketId { get { return (byte)PacketID.PlayerMoved; } }

		

		//! ID
	public uint Id = new uint();
	//! 移動データ
	public PositionPack Position = new PositionPack();
	

		public PacketPlayerMoved()
		{
		}

		public PacketPlayerMoved(uint InId, PositionPack InPosition)
	{
		Id = InId;
		Position = InPosition;
		
	}

		public override bool Serialize(IMemoryStream Stream)
{
			if(!Stream.Serialize(ref Id)) { return false; }
		if (!Position.Serialize(Stream)) { return false; }
		
			return true;
}
	}
}
