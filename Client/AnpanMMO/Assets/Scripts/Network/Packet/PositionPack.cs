using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PositionPack : 
	{

		

		

		//! X座標
	public float X;
	//! Y座標
	public float Y;
	//! Z座標
	public float Z;
	//! 回転
	public float Rotation;
	

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

		public override bool Serialize(IMemoryStream Stream)
{
			Stream.Serialize(ref X);
		Stream.Serialize(ref Y);
		Stream.Serialize(ref Z);
		Stream.Serialize(ref Rotation);
		
			return true;
}
	}
}
