using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PacketLogInResult : YanaPOnlineUtil.Packet.Packet
	{

		public override byte PacketId { get { return (byte)PacketID.LogInResult; } }

		enum ResultCode
	{
		//! 成功
		Success,
		//! 不明なエラー
		Fatal,
	};

		

		public PacketLogInResult()
		{
		}

		

		public override bool Serialize(IMemoryStream pStream)
{
			
			return true;
}
	}
}
