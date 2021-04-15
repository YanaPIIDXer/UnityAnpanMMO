using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UniRx;
using System;
using Network.Packet;
using YanaPOnlineUtil.Stream;
using YanaPOnlineUtil.Packet;

namespace Network
{
    /// <summary>
    /// 受信データ
    /// </summary>
    public class ReceiveData
    {
        /// <summary>
        /// パケットＩＤ
        /// </summary>
        public PacketID Id { get; private set; }

        /// <summary>
        /// ストリーム
        /// </summary>
        public IMemoryStream Stream { get; private set; }

        /// <summary>
        /// コンストラクタ
        /// </summary>
        /// <param name="Id">パケットＩＤ</param>
        /// <param name="Stream">ストリーム</param>
        public ReceiveData(PacketID Id, IMemoryStream Stream)
        {
            this.Id = Id;
            this.Stream = Stream;
        }
    }

    /// <summary>
    /// ゲームサーバとの接続管理
    /// </summary>
    public class GameServerConnection : MonoBehaviour
    {
        /// <summary>
        /// インスタンス
        /// </summary>
        public static GameServerConnection Instance { get; private set; }

        /// <summary>
        /// サーバとの通信オブジェクト
        /// </summary>
        private ServerConnection Connection = new ServerConnection();

        /// <summary>
        /// パケットシリアライザ
        /// </summary>
        private PacketSerializer Serializer = null;

        /// <summary>
        /// パケット受信Subject
        /// </summary>
        private static Subject<ReceiveData> PacketSubject = new Subject<ReceiveData>();

        /// <summary>
        /// パケット受信Observable
        /// </summary>
        public static IObservable<ReceiveData> OnRecvPacket { get { return PacketSubject; } }

        void Awake()
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
            Serializer = new PacketSerializer((Id, Stream) =>
            {
                ReceiveData Data = new ReceiveData((PacketID)Id, Stream);
                PacketSubject.OnNext(Data);
            }, Connection.Send);
        }

        /// <summary>
        /// 接続
        /// </summary>
        /// <returns>成功したらtrueを返す</returns>
        public bool Connect()
        {
            if (!Connection.Connect("127.0.0.1", 1234)) { return false; }
            Connection.OnRecv = OnRecvData;
            if (gameObject.GetComponent<PingSender>() == null)
            {
                gameObject.AddComponent<PingSender>();
            }
            return true;
        }

        /// <summary>
        /// パケット送信
        /// </summary>
        /// <param name="Packet">パケット</param>
        public void SendPacket(YanaPOnlineUtil.Packet.Packet Packet)
        {
            Serializer.Send(Packet);
        }

        /// <summary>
        /// データを受信した
        /// </summary>
        /// <param name="Data">データ</param>
        /// <param name="Length">データ長</param>
        private void OnRecvData(byte[] Data, int Length)
        {
            Serializer.OnRecv(Data);
        }
    }
}
