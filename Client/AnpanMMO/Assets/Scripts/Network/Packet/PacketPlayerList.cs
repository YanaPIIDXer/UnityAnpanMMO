using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PacketPlayerList : YanaPOnlineUtil.Packet.Packet
	{

		public override byte PacketId { get { return (byte)PacketID.PlayerList; } }

		

		//! データリスト
	public FlexArray<PlayerData> List = new FlexArray<PlayerData>();
	

		public PacketPlayerList()
		{
		}

		public PacketPlayerList(FlexArray<PlayerData> InList)
	{
		List = InList;
		
	}

		public override bool Serialize(IMemoryStream Stream)
{
			if (!List.Serialize(Stream)) { return false; }
		
			return true;
}
	}
}
