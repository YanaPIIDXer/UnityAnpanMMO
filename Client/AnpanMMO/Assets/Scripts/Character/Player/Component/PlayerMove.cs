using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Character.Component;

namespace Character.Player.Component
{
    /// <summary>
    /// プレイヤー移動Component
    /// </summary>
    public class PlayerMove : CharacterComponent
    {
        /// <summary>
        /// Rididbody
        /// </summary>
        private Rigidbody RigidBody = null;

        /// <summary>
        /// コンストラクタ
        /// </summary>
        public PlayerMove()
        {
        }

        /// <summary>
        /// 初期化された
        /// </summary>
        public override void OnInitialize()
        {
            RigidBody = GetOwnerComponent<Rigidbody>();
        }

        /// <summary>
        /// Update
        /// </summary>
        public override void OnUpdate()
        {
            Vector3 MoveVec = Vector3.zero;
            MoveVec.x = Input.GetAxis("Horizontal");
            MoveVec.z = Input.GetAxis("Vertical");
            MoveVec.Normalize();
            RigidBody.velocity = MoveVec;
        }
    }
}
