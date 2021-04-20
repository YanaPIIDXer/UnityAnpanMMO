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

        /// <summary>
        /// Prefabのパス
        /// </summary>
        private static readonly string PlayerPrefabPath = "Prefabs/Player";

        /// <summary>
        /// プレイヤーDictionary
        /// </summary>
        private Dictionary<uint, Player> PlayerDic = new Dictionary<uint, Player>();

        void Awake()
        {
            GameServerConnection.PacketMethods[PacketID.PlayerPositionChange] = (Stream) =>
            {
                PacketPlayerPositionChange Packet = new PacketPlayerPositionChange();
                Packet.Serialize(Stream);
                if (PlayerPrefab == null)
                {
                    PlayerPrefab = Resources.Load<GameObject>(PlayerPrefabPath);
                    Debug.Assert(PlayerPrefab != null);
                }

                Vector3 Position = new Vector3(Packet.Position.X, Packet.Position.Y, Packet.Position.Z);
                float Rotation = Packet.Position.Rotation;
                var PlayerObj = Instantiate<GameObject>(PlayerPrefab, Position, Quaternion.Euler(0.0f, Rotation, 0.0f));
                PlayerDic.Add(PlayerData.PlayerId, PlayerObj.GetComponent<Player>());
            };

            GameServerConnection.PacketMethods[PacketID.PlayerList] = (Stream) =>
            {
                PacketPlayerList Packet = new PacketPlayerList();
                Packet.Serialize(Stream);
                foreach (var Data in Packet.List)
                {
                    Spawn(Data);
                }
            };

            GameServerConnection.PacketMethods[PacketID.PlayerEntry] = (Stream) =>
            {
                PacketPlayerEntry Packet = new PacketPlayerEntry();
                Packet.Serialize(Stream);
                Spawn(Packet.Data);
            };
        }

        /// <summary>
        /// Spawn
        /// </summary>
        /// <param name="Data">データ</param>
        private void Spawn(Network.Packet.PlayerData Data)
        {
            if (PlayerPrefab == null)
            {
                PlayerPrefab = Resources.Load<GameObject>(PlayerPrefabPath);
                Debug.Assert(PlayerPrefab != null);
            }

            Vector3 Position = new Vector3(Data.Position.X, Data.Position.Y, Data.Position.Z);
            float Rotation = Data.Position.Rotation;
            var PlayerObj = Instantiate<GameObject>(PlayerPrefab, Position, Quaternion.Euler(0.0f, Rotation, 0.0f));
            PlayerDic.Add(Data.Id, PlayerObj.GetComponent<Player>());
        }
    }
}
