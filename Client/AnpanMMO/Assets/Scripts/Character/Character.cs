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
        /// 移動Component
        /// </summary>
        private CharacterMove MoveCmp = new CharacterMove();

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

        void Awake()
        {
            AddCharacterComponent(MoveCmp);
            Init();
        }

        /// <summary>
        /// 移動をセット
        /// </summary>
        /// <param name="Destination">行先</param>
        /// <param name="MoveTime">移動時間</param>
        public void SetMove(Vector3 Destination, float MoveTime)
        {
            MoveCmp.SetMove(Destination, MoveTime);
        }

        /// <summary>
        /// 初期化
        /// </summary>
        protected abstract void Init();

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
