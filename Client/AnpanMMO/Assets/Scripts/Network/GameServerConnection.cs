using System.Collections;
using System.Collections.Generic;
using UnityEngine;

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
        /// サーバとの通信オブジェクト
        /// </summary>
        private ServerConnection Connection = new ServerConnection();

        void Awake()
        {
            Instance = this;
        }

        /// <summary>
        /// 接続
        /// </summary>
        /// <returns>成功したらtrueを返す</returns>
        public bool Connect()
        {
            if (!Connection.Connect("127.0.0.1", 1234)) { return false; }
            Connection.OnRecv = OnRecvData;
            return true;
        }

        /// <summary>
        /// データを受信した
        /// </summary>
        /// <param name="Data">データ</param>
        /// <param name="Length">データ長</param>
        private void OnRecvData(byte[] Data, int Length)
        {
        }
    }
}
