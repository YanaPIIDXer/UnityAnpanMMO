namespace Network.Packet
{
    public enum PacketID
	{
		//! エリア切り替え要求パケット
		AreaChange = 0x01,
		//! エリア切り替え完了パケット
		AreaLoadEnd = 0x02,
		//! プレイヤー位置変更パケット
		PlayerPositionChange = 0x03,
		//! エネミーリストパケット
		EnemyList = 0x04,
		//! エネミー出現パケット
		EnemyEntry = 0x05,
		//! LogInResultパケット
		LogInResult = 0x06,
		//! LogInRequestパケット
		LogInRequest = 0x07,
		//! Pingパケット
		Ping = 0x08,
		
	}
}
