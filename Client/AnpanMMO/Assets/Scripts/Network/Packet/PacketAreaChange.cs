using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PacketAreaChange : YanaPOnlineUtil.Packet.Packet
	{

		public override byte PacketId { get { return (byte)PacketID.AreaChange; } }

		

		//! エリアID
	public uint AreaId = new uint();
	

		public PacketAreaChange()
		{
		}

		public PacketAreaChange(uint InAreaId)
	{
		AreaId = InAreaId;
		
	}

		public override bool Serialize(IMemoryStream Stream)
{
			if(!Stream.Serialize(ref AreaId)) { return false; }
		
			return true;
}
	}
}
