using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using UniRx;
using Network.Packet;

namespace Network
{
    /// <summary>
    /// Ping送受信
    /// </summary>
    public class PingSender : MonoBehaviour
    {
        /// <summary>
        /// インターバル
        /// </summary>
        private static readonly float Interval = 10.0f;

        /// <summary>
        /// 最後にPingを受信してからの経過時間
        /// </summary>
        private float ElapsedTime = 0.0f;

        /// <summary>
        /// タイムアウトしたか？
        /// </summary>
        private bool bIsTimeout = false;

        /// <summary>
        /// Pingを受信しているか？
        /// </summary>
        private bool bRecvPing = false;

        /// <summary>
        /// タイムアウトSubject
        /// </summary>
        private Subject<Unit> TimeoutSubject = new Subject<Unit>();

        /// <summary>
        /// タイムアウトした
        /// </summary>
        public IObservable<Unit> OnTimeout { get { return TimeoutSubject; } }

        void Awake()
        {
            GameServerConnection.OnRecvPacket
                .Select((Data) => Data.Id == PacketID.Ping)
                .Subscribe((_) => bRecvPing = true);
        }

        void Update()
        {
            if (bIsTimeout) { return; }
            ElapsedTime += Time.deltaTime;
            if (ElapsedTime >= Interval)
            {
                if (!bRecvPing)
                {
                    bIsTimeout = true;
                    TimeoutSubject.OnNext(Unit.Default);
                    return;
                }
                GameServerConnection.Instance.SendPacket(new PacketPing());
                ElapsedTime -= Interval;
            }
        }
    }
}
