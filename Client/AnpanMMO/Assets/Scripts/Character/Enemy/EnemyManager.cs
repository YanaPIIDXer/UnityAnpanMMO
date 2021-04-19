using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Network;
using Network.Packet;
using YanaPOnlineUtil.Stream;
using Character.Enemy;

namespace Character.Enemy
{
    /// <summary>
    /// エネミー管理
    /// </summary>
    public class EnemyManager : MonoBehaviour
    {
        /// <summary>
        /// Prefabのパス
        /// </summary>
        private static readonly string PrefabPath = "Prefabs/Enemy";

        /// <summary>
        /// Prefab
        /// </summary>
        private static GameObject Prefab = null;

        /// <summary>
        /// エネミーディクショナリ
        /// </summary>
        /// <typeparam name="Enemy"></typeparam>
        /// <returns></returns>
        private Dictionary<uint, Enemy> EnemyDict = new Dictionary<uint, Enemy>();

        /// <summary>
        /// 生成待ちリスト
        /// ※コールバックの中でSpawnできないのでこういった対処を行っている
        /// </summary>
        private List<EnemyData> SpawnList = new List<EnemyData>();

        void Awake()
        {
            // FIXME:届いていないので調査
            GameServerConnection.PacketMethods[PacketID.EnemyList] = (Stream) =>
            {
                PacketEnemyList Packet = new PacketEnemyList();
                Packet.Serialize(Stream);
                foreach (var EnData in Packet.List)
                {
                    SpawnList.Add(EnData);
                }
            };

            GameServerConnection.PacketMethods[PacketID.EnemyEntry] = (Stream) =>
            {
                PacketEnemyEntry Packet = new PacketEnemyEntry();
                Packet.Serialize(Stream);
                SpawnList.Add(Packet.Data);
            };
        }

        void Update()
        {
            if (SpawnList.Count == 0) { return; }
            var Data = SpawnList[0];
            SpawnList.RemoveAt(0);
            Spawn(Data);
        }

        /// <summary>
        /// エネミー生成
        /// </summary>
        /// <param name="Data">サーバから受信したエネミーデータ</param>
        private void Spawn(EnemyData Data)
        {
            if (Prefab == null)
            {
                Prefab = Resources.Load<GameObject>(PrefabPath);
                Debug.Assert(Prefab != null);
            }

            Vector3 Position = new Vector3(Data.Position.X, Data.Position.Y, Data.Position.Z);
            float Rotation = Data.Position.Rotation;
            var EnemyObj = Instantiate<GameObject>(Prefab, Position, Quaternion.Euler(0.0f, Rotation, 0.0f));
            EnemyDict.Add(Data.Id, EnemyObj.GetComponent<Enemy>());
        }
    }
}
