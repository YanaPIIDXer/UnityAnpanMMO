using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PositionPack : YanaPOnlineUtil.ISerializable
	{

		

		

		//! X座標
	public float X = new float();
	//! Y座標
	public float Y = new float();
	//! Z座標
	public float Z = new float();
	//! 回転
	public float Rotation = new float();
	

		public PositionPack()
		{
		}

		public PositionPack(float InX, float InY, float InZ, float InRotation)
	{
		X = InX;
		Y = InY;
		Z = InZ;
		Rotation = InRotation;
		
	}

		public bool Serialize(IMemoryStream Stream)
{
			if(!Stream.Serialize(ref X)) { return false; }
		if(!Stream.Serialize(ref Y)) { return false; }
		if(!Stream.Serialize(ref Z)) { return false; }
		if(!Stream.Serialize(ref Rotation)) { return false; }
		
			return true;
}
	}
}
