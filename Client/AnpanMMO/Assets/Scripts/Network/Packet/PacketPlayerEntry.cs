using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PacketPlayerEntry : YanaPOnlineUtil.Packet.Packet
	{

		public override byte PacketId { get { return (byte)PacketID.PlayerEntry; } }

		

		//! データ
	public PlayerData Data = new PlayerData();
	

		public PacketPlayerEntry()
		{
		}

		public PacketPlayerEntry(PlayerData InData)
	{
		Data = InData;
		
	}

		public override bool Serialize(IMemoryStream Stream)
{
			if (!Data.Serialize(Stream)) { return false; }
		
			return true;
}
	}
}
