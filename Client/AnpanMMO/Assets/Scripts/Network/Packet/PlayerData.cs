using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PlayerData : YanaPOnlineUtil.ISerializable
	{

		

		

		//! ID
	public uint Id = new uint();
	//! 座標
	public PositionPack Position = new PositionPack();
	

		public PlayerData()
		{
		}

		public PlayerData(uint InId, PositionPack InPosition)
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
