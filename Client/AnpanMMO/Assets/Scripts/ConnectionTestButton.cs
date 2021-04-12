using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Network;
using YanaPOnlineUtil.Packet;
using YanaPOnlineUtil.Stream;
using Network.Packet;

/// <summary>
/// 接続テストボタン
/// そのうち消す
/// </summary>
public class ConnectionTestButton : MonoBehaviour
{
    /// <summary>
    /// 通信オブジェクト
    /// </summary>
    private ServerConnection Connection = new ServerConnection();

    /// <summary>
    /// パケットシリアライザ
    /// </summary>
    private PacketSerializer Serializer = null;

    void Awake()
    {
        Serializer = new PacketSerializer(OnRecvPacket, Connection.Send);
    }

    /// <summary>
    /// ボタン押下時の処理
    /// </summary>
    public void ButtionAction()
    {
        if (Connection.IsConnected) { return; }
        Connection.OnRecv = OnRecvData;
        if (!Connection.Connect("localhost", 1234))
        {
            Debug.Log("Connection Failed.");
            return;
        }
        Debug.Log("Connection Success!");
        Serializer.Send(new PacketLogInRequest());
    }

    /// <summary>
    /// 受信した
    /// </summary>
    /// <param name="Data">受信データ</param>
    /// <param name="Length">データ長</param>
    private void OnRecvData(byte[] Data, int Length)
    {
        // FIXME:これゴミデータ付いてこない・・・？
        Serializer.OnRecv(Data);
    }

    /// <summary>
    /// パケット受信
    /// </summary>
    /// <param name="PacketID">パケットＩＤ</param>
    /// <param name="Stream">メモリストリーム</param>
    private void OnRecvPacket(uint PacketID, IMemoryStream Stream)
    {
        switch ((Network.Packet.PacketID)PacketID)
        {
            case Network.Packet.PacketID.Ping:

                Debug.Log("Receive Ping!");
                break;

            case Network.Packet.PacketID.LogInResult:

                {
                    PacketLogInResult Result = new PacketLogInResult();
                    Result.Serialize(Stream);
                }
                break;
        }
    }

    void OnDestroy()
    {
        Debug.Log("Disconnect");
        Connection.Disconnect();
    }
}
