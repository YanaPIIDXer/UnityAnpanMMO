using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Network;
using Network.Packet;
using System;
using UniRx;

namespace Character.Enemy
{
    /// <summary>
    /// エネミー管理
    /// </summary>
    public class EnemyManager : MonoBehaviour
    {
        void Awake()
        {
            GameServerConnection.OnRecvPacket
                .Where((Data) => Data.Id == PacketID.EnemyList)
                .Subscribe((Data) =>
                {
                    PacketEnemyList Packet = new PacketEnemyList();
                    Packet.Serialize(Data.Stream);
                    foreach (var EnData in Packet.List)
                    {
                        Spawn(EnData);
                    }
                });

            GameServerConnection.OnRecvPacket
                .Where((Data) => Data.Id == PacketID.EnemyEntry)
                .Subscribe((Data) =>
                {
                    PacketEnemyEntry Packet = new PacketEnemyEntry();
                    Packet.Serialize(Data.Stream);
                    Spawn(Packet.Data);
                });
        }

        /// <summary>
        /// エネミー生成
        /// </summary>
        /// <param name="Data">サーバから受信したエネミーデータ</param>
        private void Spawn(EnemyData Data)
        {
            Vector3 Position = new Vector3(Data.Position.X, Data.Position.Y, Data.Position.Z);
            Debug.Log("Spawn Enemy At:" + Position.ToString());
        }
    }
}
