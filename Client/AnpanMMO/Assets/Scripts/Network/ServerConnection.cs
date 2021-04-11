using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Net.Sockets;

namespace Network
{
    /// <summary>
    /// サーバとの接続
    /// </summary>
    public class ServerConnection
    {
        /// <summary>
        /// ソケット
        /// </summary>
        private Socket Sock = null;

        /// <summary>
        /// 接続されているか？
        /// </summary>
        public bool IsConnected { get { return (Sock != null && Sock.Connected); } }

        /// <summary>
        /// コンストラクタ
        /// </summary>
        public ServerConnection()
        {
        }

        /// <summary>
        /// 接続
        /// TODO:ConnectAsyncを使った非同期処理に置き換える
        /// </summary>
        /// <param name="Host">ホスト</param>
        /// <param name="Port">ポート</param>
        /// <returns>接続したらtrue</returns>
        public bool Connect(string Host, int Port)
        {
            try
            {
                Sock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                Sock.Connect(Host, Port);
            }
            catch (Exception e)
            {
                Debug.Log(e.Message);
                return false;
            }
            return true;
        }

        /// <summary>
        /// 送信
        /// </summary>
        /// <param name="Data">送信するデータ</param>
        public void Send(byte[] Data)
        {
            if (!IsConnected) { return; }
            Sock.Send(Data);
        }

        /// <summary>
        /// 切断
        /// </summary>
        public void Disconnect()
        {
            if (Sock == null) { return; }
            Sock.Close();
            Sock = null;
        }
    }
}
