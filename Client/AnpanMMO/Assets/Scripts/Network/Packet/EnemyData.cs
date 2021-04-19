using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class EnemyData : YanaPOnlineUtil.ISerializable
	{

		

		

		//! ID
	public uint Id = new uint();
	//! 座標
	public PositionPack Position = new PositionPack();
	

		public EnemyData()
		{
		}

		public EnemyData(uint InId, PositionPack InPosition)
	{
		Id = InId;
		Position = InPosition;
		
	}

		public bool Serialize(IMemoryStream Stream)
{
			if(!Stream.Serialize(ref Id)) { return false; }
		if (!Position.Serialize(Stream)) { return false; }
		
			return true;
}
	}
}
