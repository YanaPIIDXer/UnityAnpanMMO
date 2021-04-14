namespace Network.Packet
{
    public enum PacketID
	{
		//! エネミーリストパケット
		EnemyList = 0x01,
		//! エネミー出現パケット
		EnemyEntry = 0x02,
		//! LogInResultパケット
		LogInResult = 0x03,
		//! LogInRequestパケット
		LogInRequest = 0x04,
		//! Pingパケット
		Ping = 0x05,
		
	}
}
