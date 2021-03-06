using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PacketEnemyList : YanaPOnlineUtil.Packet.Packet
	{

		public override byte PacketId { get { return (byte)PacketID.EnemyList; } }

		

		//! データリスト
	public FlexArray<EnemyData> List = new FlexArray<EnemyData>();
	

		public PacketEnemyList()
		{
		}

		public PacketEnemyList(FlexArray<EnemyData> InList)
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
