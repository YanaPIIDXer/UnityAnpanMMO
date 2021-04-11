using YanaPOnlineUtil.Stream;

namespace Network.Packet
{
    public class PacketPing : YanaPOnlineUtil.Packet.Packet
    {

        public override byte PacketId { get { return (byte)PacketID.Ping; } }





        public PacketPing()
        {
        }



        public override bool Serialize(IMemoryStream pStream)
        {

            return true;
        }
    }
}
