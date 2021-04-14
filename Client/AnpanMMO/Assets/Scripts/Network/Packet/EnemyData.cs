using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class EnemyData : YanaPOnlineUtil.ISerializable
	{

		

		

		//! ID
	public uint Id;
	//! 座標
	public PositionPack Position;
	

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
			Stream.Serialize(ref Id);
		Position.Serialize(Stream);
		
			return true;
}
	}
}
