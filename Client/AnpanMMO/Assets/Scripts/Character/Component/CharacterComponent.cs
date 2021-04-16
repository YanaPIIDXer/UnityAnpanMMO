using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Character.Component
{
    /// <summary>
    /// キャラクタコンポーネント基底クラス
    /// </summary>
    public abstract class CharacterComponent
    {
        /// <summary>
        /// 所有者
        /// </summary>
        private Character Owner = null;

        /// <summary>
        /// コンストラクタ
        /// </summary>
        /// <param name="Owner">所有者</param>
        public CharacterComponent(Character Owner)
        {
            this.Owner = Owner;
        }

        /// <summary>
        /// MonoBehaviour派生のComponentを取得
        /// ※GetComponent<T>()
        /// </summary>
        /// <typeparam name="T">Componentの型</typeparam>
        /// <returns>Component</returns>
        public T GetOwnerComponent<T>()
        {
            return Owner.GetComponent<T>();
        }

        /// <summary>
        /// 初期化
        /// </summary>
        public virtual void OnInitialize() { }

        /// <summary>
        /// Update
        /// </summary>
        public virtual void OnUpdate() { }

        /// <summary>
        /// FixedUpdate
        /// </summary>
        public virtual void OnFixedUpdate() { }
    }
}
