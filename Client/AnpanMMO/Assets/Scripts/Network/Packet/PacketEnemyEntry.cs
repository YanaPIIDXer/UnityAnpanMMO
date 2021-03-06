using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PacketEnemyEntry : YanaPOnlineUtil.Packet.Packet
	{

		public override byte PacketId { get { return (byte)PacketID.EnemyEntry; } }

		

		//! データ
	public EnemyData Data = new EnemyData();
	

		public PacketEnemyEntry()
		{
		}

		public PacketEnemyEntry(EnemyData InData)
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
