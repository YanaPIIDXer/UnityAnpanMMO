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
            AddCharacterComponent(new PlayerMove());
        }
    }
}
