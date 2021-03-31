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
        /// TCPクライアント
        /// </summary>
        private TcpClient Client = null;

        /// <summary>
        /// 接続されているか？
        /// </summary>
        public bool IsConnected { get { return (Client != null && Client.Connected); } }

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
                Client = new TcpClient();
                Client.Connect(Host, Port);
            }
            catch
            {
                return false;
            }
            return true;
        }

        /// <summary>
        /// 切断
        /// </summary>
        public void Disconnect()
        {
            if (Client == null) { return; }
            Client.Close();
            Client = null;
        }
    }
}
