namespace Network.Packet
{
    public enum PacketID
	{
		//! エリア切り替え要求パケット
		AreaChange = 0x01,
		//! エリア切り替え完了パケット
		AreaLoadEnd = 0x02,
		//! エネミーリストパケット
		EnemyList = 0x03,
		//! エネミー出現パケット
		EnemyEntry = 0x04,
		//! LogInResultパケット
		LogInResult = 0x05,
		//! LogInRequestパケット
		LogInRequest = 0x06,
		//! Pingパケット
		Ping = 0x07,
		
	}
}
