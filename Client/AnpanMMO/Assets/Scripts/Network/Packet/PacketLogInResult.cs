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
	public byte Result = new byte();
	//! キャラクタID
	public uint CharacterId = new uint();
	

		public PacketLogInResult()
		{
		}

		public PacketLogInResult(byte InResult, uint InCharacterId)
	{
		Result = InResult;
		CharacterId = InCharacterId;
		
	}

		public override bool Serialize(IMemoryStream Stream)
{
			if(!Stream.Serialize(ref Result)) { return false; }
		if(!Stream.Serialize(ref CharacterId)) { return false; }
		
			return true;
}
	}
}
