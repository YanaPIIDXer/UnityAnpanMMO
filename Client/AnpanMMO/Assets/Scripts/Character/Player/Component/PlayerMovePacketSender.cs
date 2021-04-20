using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Character.Component;
using Network;
using Network.Packet;

namespace Character.Player.Component
{
    /// <summary>
    /// 移動パケット送信クラス
    /// </summary>
    public class PlayerMovePacketSender : CharacterComponent
    {
        /// <summary>
        /// 送信間隔
        /// </summary>
        private static readonly float Interval = 1.5f;

        /// <summary>
        /// 経過時間
        /// </summary>
        private float ElapsedTime = 0.0f;

        /// <summary>
        /// 以前の座標
        /// </summary>
        private Vector3 PrevPosition = Vector3.zero;

        /// <summary>
        /// 所有者のtransform
        /// </summary>
        private Transform OwnerTransform = null;

        /// <summary>
        /// 初期化された
        /// </summary>
        public override void OnInitialize()
        {
            OwnerTransform = GetOwnerComponent<Transform>();
            PrevPosition = OwnerTransform.position;
        }

        /// <summary>
        /// Update
        /// </summary>
        public override void OnUpdate()
        {
            ElapsedTime += Time.deltaTime;
            if (ElapsedTime >= Interval)
            {
                ElapsedTime -= Interval;
                if (!OwnerTransform.position.Equals(PrevPosition))
                {
                    PrevPosition = OwnerTransform.position;
                    PacketPlayerMove Packet = new PacketPlayerMove(new PositionPack(PrevPosition.x, PrevPosition.y, PrevPosition.z, OwnerTransform.eulerAngles.y));
                    GameServerConnection.Instance.SendPacket(Packet);
                }

            }
        }
    }
}
