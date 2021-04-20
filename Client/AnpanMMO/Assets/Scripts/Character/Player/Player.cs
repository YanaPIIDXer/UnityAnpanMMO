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
        void Awake()
        {
            AddCharacterComponent(new PlayerMove());
        }
    }
}
