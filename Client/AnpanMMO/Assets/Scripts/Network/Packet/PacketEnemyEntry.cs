using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PacketEnemyEntry : YanaPOnlineUtil.Packet.Packet
    {

        public override byte PacketId { get { return (byte)PacketID.EnemyEntry; } }



        //! 座標
        public PositionPack Position;


        public PacketEnemyEntry()
        {
        }

        public PacketEnemyEntry(PositionPack InPosition)
        {
            Position = InPosition;

        }

        public override bool Serialize(IMemoryStream Stream)
        {
            Position.Serialize(Stream);

            return true;
        }
    }
}
