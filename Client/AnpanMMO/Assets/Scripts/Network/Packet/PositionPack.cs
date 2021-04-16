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
			Stream.Serialize(ref X);
		Stream.Serialize(ref Y);
		Stream.Serialize(ref Z);
		Stream.Serialize(ref Rotation);
		
			return true;
}
	}
}
