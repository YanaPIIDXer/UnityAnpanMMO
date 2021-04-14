using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PacketEnemyEntry : YanaPOnlineUtil.Packet.Packet
	{

		public override byte PacketId { get { return (byte)PacketID.EnemyEntry; } }

		

		//! データ
	public EnemyData Data;
	

		public PacketEnemyEntry()
		{
		}

		public PacketEnemyEntry(EnemyData InData)
	{
		Data = InData;
		
	}

		public override bool Serialize(IMemoryStream Stream)
{
			Data.Serialize(Stream);
		
			return true;
}
	}
}
