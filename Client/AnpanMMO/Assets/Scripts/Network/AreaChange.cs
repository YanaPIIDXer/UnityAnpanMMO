using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Network.Packet;
using UnityEngine.SceneManagement;
using YanaPOnlineUtil.Stream;

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
        /// ゲームシーンか？
        /// </summary>
        private bool bIsGameScene = false;

        /// <summary>
        /// 読み込んでいるシーン名
        /// </summary>
        private string LoadingSceneName = "";

        void Awake()
        {
            DontDestroyOnLoad(gameObject);
            GameServerConnection.PacketMethods[PacketID.AreaChange] += OnRecvAreaChange;
        }

        void Update()
        {
            if (LoadingSceneName == "") { return; }

            if (!bIsGameScene)
            {
                // ゲームシーンではない場合は一旦ゲームシーンを読み込む
                bIsGameScene = true;
                SceneManager.LoadScene("Game");
                return;
            }

            SceneManager.LoadScene(LoadingSceneName, LoadSceneMode.Additive);
            LoadingSceneName = "";
            GameServerConnection.Instance.SendPacket(new PacketAreaLoadEnd());
        }

        /// <summary>
        /// エリア切り替えを受信した
        /// </summary>
        /// <param name="Data">受信データ</param>
        private void OnRecvAreaChange(IMemoryStream Stream)
        {
            PacketAreaChange Packet = new PacketAreaChange();
            Packet.Serialize(Stream);
            LoadingSceneName = ScenePrefix + string.Format("{0:D6}", Packet.AreaId);
        }
    }
}
