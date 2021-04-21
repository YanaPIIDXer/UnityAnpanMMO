using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Character.Component
{
    /// <summary>
    /// キャラクタ移動
    /// ※他人やエネミーでの使用を想定
    /// </summary>
    public class CharacterMove : CharacterComponent
    {
        /// <summary>
        /// 移動中？
        /// </summary>
        private bool IsMoving { get { return (LastTime > 0.0f); } }

        /// <summary>
        /// 移動ベクトル
        /// </summary>
        private Vector3 MoveVector = Vector3.zero;

        /// <summary>
        /// 所有者のTransform
        /// </summary>
        private Transform OwnerTrans = null;

        /// <summary>
        /// 残り移動時間
        /// </summary>
        private float LastTime = 0.0f;

        /// <summary>
        /// 行先
        /// </summary>
        private Vector3 Destination = Vector3.zero;

        /// <summary>
        /// コンストラクタ
        /// </summary>
        public CharacterMove()
        {
        }

        /// <summary>
        /// 初期化された
        /// </summary>
        public override void OnInitialize()
        {
            OwnerTrans = GetOwnerComponent<Transform>();
        }

        /// <summary>
        /// 更新
        /// </summary>
        public override void OnUpdate()
        {
            if (!IsMoving) { return; }

            OwnerTrans.position += MoveVector;
            LastTime -= Time.deltaTime;
            if (LastTime <= 0.0f)
            {
                OwnerTrans.position = Destination;
            }
        }

        /// <summary>
        /// 移動をセット
        /// </summary>
        /// <param name="Dest">行先</param>
        /// <param name="MoveTime">移動にかかる秒数</param>
        public void SetMove(Vector3 Dest, float MoveTime)
        {
            Destination = Dest;
            LastTime = MoveTime;

            MoveVector = (Dest - OwnerTrans.position) / MoveTime;
        }
    }
}
