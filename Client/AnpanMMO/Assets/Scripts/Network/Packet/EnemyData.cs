using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class EnemyData 
	{

		

		

		//! 座標
	public PositionPack Position;
	

		public EnemyData()
		{
		}

		public EnemyData(PositionPack InPosition)
	{
		Position = InPosition;
		
	}

		public bool Serialize(IMemoryStream Stream)
{
			Position.Serialize(Stream);
		
			return true;
}
	}
}
