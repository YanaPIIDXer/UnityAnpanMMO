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

        void Awake()
        {
            DontDestroyOnLoad(gameObject);
            GameServerConnection.PacketMethods[PacketID.AreaChange] = (Stream) =>
            {
                PacketAreaChange Packet = new PacketAreaChange();
                Packet.Serialize(Stream);

                if (!bIsGameScene)
                {
                    // ゲームシーンではない場合は一旦ゲームシーンを読み込む
                    bIsGameScene = true;
                    SceneManager.LoadScene("Game");
                }
                var SceneName = ScenePrefix + string.Format("{0:D6}", Packet.AreaId);
                SceneManager.LoadScene(SceneName, LoadSceneMode.Additive);
                GameServerConnection.Instance.SendPacket(new PacketAreaLoadEnd());
            };
        }
    }
}
