using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PacketLogInResult : YanaPOnlineUtil.Packet.Packet
	{

		public override byte PacketId { get { return (byte)PacketID.LogInResult; } }

		public enum ResultCode
	{
		//! 成功
		Success,
		//! 不明なエラー
		Fatal,
	};

		//! リザルトコード
	public int Result;
	

		public PacketLogInResult()
		{
		}

		public PacketLogInResult(int InResult)
	{
		Result = InResult;
		
	}

		public override bool Serialize(IMemoryStream Stream)
{
			Stream.Serialize(ref Result);
		
			return true;
}
	}
}
