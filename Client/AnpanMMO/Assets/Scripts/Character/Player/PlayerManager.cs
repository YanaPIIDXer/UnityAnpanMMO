using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Network;
using Network.Packet;

namespace Character.Player
{
    /// <summary>
    /// プレイヤーマネージャ
    /// </summary>
    public class PlayerManager : MonoBehaviour
    {
        /// <summary>
        /// プレイヤーのPrefab
        /// </summary>
        private static GameObject PlayerPrefab = null;

        private static readonly string PlayerPrefabPath = "Prefabs/Player";

        void Awake()
        {
            GameServerConnection.PacketMethods[PacketID.PlayerPositionChange] = (Stream) =>
            {
                PacketPlayerPositionChange Packet = new PacketPlayerPositionChange();
                Packet.Serialize(Stream);
                // HACK:「キャラがまた生成されていない」と言う前提
                if (PlayerPrefab == null)
                {
                    PlayerPrefab = Resources.Load<GameObject>(PlayerPrefabPath);
                    Debug.Assert(PlayerPrefab != null);
                }

                Vector3 Position = new Vector3(Packet.Position.X, Packet.Position.Y, Packet.Position.Z);
                float Rotation = Packet.Position.Rotation;
                Instantiate<GameObject>(PlayerPrefab, Position, Quaternion.Euler(0.0f, Rotation, 0.0f));
            };
        }
    }
}
