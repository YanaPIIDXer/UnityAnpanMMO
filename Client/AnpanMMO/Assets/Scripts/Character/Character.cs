using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Character.Component;

namespace Character
{
    /// <summary>
    /// キャラクタ基底クラス
    /// </summary>
    public abstract class Character : MonoBehaviour
    {
        /// <summary>
        /// コンポーネントリスト
        /// </summary>
        private List<CharacterComponent> Components = new List<CharacterComponent>();

        /// <summary>
        /// キャラクタコンポーネントを追加
        /// </summary>
        /// <param name="Cmp"></param>
        protected void AddCharacterComponent(CharacterComponent Cmp)
        {
            Cmp.SetOwner(this);
            Components.Add(Cmp);
            Cmp.OnInitialize();
        }

        void Update()
        {
            foreach (var Cmp in Components)
            {
                Cmp.OnUpdate();
            }
        }

        void FixedUpdate()
        {
            foreach (var Cmp in Components)
            {
                Cmp.OnFixedUpdate();
            }
        }
    }
}
