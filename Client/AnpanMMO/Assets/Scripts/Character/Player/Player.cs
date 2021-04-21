using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Character.Component;
using Character.Player.Component;

namespace Character.Player
{
    /// <summary>
    /// プレイヤー
    /// </summary>
    public class Player : Character
    {
        /// <summary>
        /// 初期化
        /// </summary>
        protected override void Init()
        {
        }

        /// <summary>
        /// 自分が操作するキャラとして初期化
        /// </summary>
        public void InitializeAsPlayerCharacter()
        {
            AddCharacterComponent(new PlayerMove());
            AddCharacterComponent(new PlayerMovePacketSender());
        }
    }
}
