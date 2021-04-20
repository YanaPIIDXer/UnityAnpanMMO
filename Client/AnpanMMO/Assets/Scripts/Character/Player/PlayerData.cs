using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Character.Player
{
    /// <summary>
    /// プレイヤーデータ
    /// シーンを跨いで保持しておくべきデータを放り込むクラス
    /// HACK:きれいな作りとは言えないが止む無し
    /// </summary>
    public static class PlayerData
    {
        /// <summary>
        /// プレイヤーＩＤ
        /// </summary>
        public static uint PlayerId = 0;
    }
}
