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
            return Connection.Connect("127.0.0.1", 1234);
        }
    }
}
