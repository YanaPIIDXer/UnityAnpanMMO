using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Network.Packet;
using System;
using UniRx;
using UnityEngine.SceneManagement;

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

        /// <summary>
        /// 読み込んでいるシーン名
        /// </summary>
        private string LoadingSceneName = "";

        void Awake()
        {
            DontDestroyOnLoad(gameObject);
            GameServerConnection.OnRecvPacket
                .Where((Data) => Data.Id == PacketID.AreaChange)
                .Subscribe(OnRecvAreaChange);
        }

        void Update()
        {
            if (LoadingSceneName == "") { return; }

            SceneManager.LoadScene(LoadingSceneName);
            LoadingSceneName = "";
            GameServerConnection.Instance.SendPacket(new PacketAreaLoadEnd());
        }

        /// <summary>
        /// エリア切り替えを受信した
        /// </summary>
        /// <param name="Data">受信データ</param>
        private void OnRecvAreaChange(ReceiveData Data)
        {
            PacketAreaChange Packet = new PacketAreaChange();
            Packet.Serialize(Data.Stream);
            LoadingSceneName = ScenePrefix + string.Format("{0:D6}", Packet.AreaId);
        }
    }
}
