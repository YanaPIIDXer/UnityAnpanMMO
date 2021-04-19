using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Network.Packet;
using YanaPOnlineUtil.Stream;
using YanaPOnlineUtil.Packet;

namespace Network
{
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
        /// 接続されているか？
        /// </summary>
        public bool IsConnected { get { return Connection.IsConnected; } }

        /// <summary>
        /// サーバとの通信オブジェクト
        /// </summary>
        private ServerConnection Connection = new ServerConnection();

        /// <summary>
        /// パケットシリアライザ
        /// </summary>
        private PacketSerializer Serializer = null;

        /// <summary>
        /// パケット受信Observable
        /// </summary>
        public static Dictionary<PacketID, Action<IMemoryStream>> PacketMethods
        {
            get
            {
                if (_PacketMethods == null)
                {
                    _PacketMethods = new Dictionary<PacketID, Action<IMemoryStream>>();
                    foreach (var Id in Enum.GetValues(typeof(PacketID)))
                    {
                        _PacketMethods.Add((PacketID)Id, null);
                    }
                }
                return _PacketMethods;
            }
        }
        private static Dictionary<PacketID, Action<IMemoryStream>> _PacketMethods = null;

        void Awake()
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
            Serializer = new PacketSerializer((Id, Stream) =>
            {
                PacketMethods[(PacketID)Id]?.Invoke(Stream);
            }, Connection.Send);
        }

        void Update()
        {
            if (IsConnected)
            {
                Serializer.Poll();
            }
        }

        /// <summary>
        /// 接続
        /// </summary>
        /// <returns>成功したらtrueを返す</returns>
        public bool Connect()
        {
            if (IsConnected) { return true; }
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
            Serializer.OnRecv(Data, Length);
        }
    }
}
