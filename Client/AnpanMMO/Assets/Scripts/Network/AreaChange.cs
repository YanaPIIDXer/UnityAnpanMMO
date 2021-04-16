using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Network.Packet;
using System;
using UniRx;

namespace Network
{
    /// <summary>
    /// エリア切り替え
    /// </summary>
    public class AreaChange : MonoBehaviour
    {
        /// <summary>
        /// シーンファイルプレフィクス
        /// </summary>
        private static readonly string ScenePrefix = "Area";

        void Awake()
        {
            DontDestroyOnLoad(gameObject);
            GameServerConnection.OnRecvPacket
                .Where((Data) => Data.Id == PacketID.AreaChange)
                .Subscribe((Data) =>
                {
                    Debug.Log("Area Change");
                    // TODO:実際のロード処理
                    GameServerConnection.Instance.SendPacket(new PacketAreaLoadEnd());
                });
        }
    }
}
