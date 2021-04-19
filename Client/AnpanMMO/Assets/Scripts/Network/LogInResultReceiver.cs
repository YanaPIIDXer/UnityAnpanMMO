using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using UniRx;
using Network.Packet;
using YanaPOnlineUtil.Stream;

namespace Network
{
    /// <summary>
    /// ログイン結果受信
    /// </summary>
    public class LogInResultReceiver : MonoBehaviour
    {
        /// <summary>
        /// ログイン成功Subject
        /// </summary>
        private Subject<Unit> LogInSuccessSubject = new Subject<Unit>();

        /// <summary>
        /// ログインに成功した
        /// </summary>
        public IObservable<Unit> OnLogInSuccess { get { return LogInSuccessSubject; } }

        /// <summary>
        /// ログイン失敗Subject
        /// </summary>
        private Subject<PacketLogInResult.ResultCode> LogInFailedSubject = new Subject<PacketLogInResult.ResultCode>();

        /// <summary>
        /// ログインに失敗した
        /// </summary>
        public IObservable<PacketLogInResult.ResultCode> OnLogInFailed { get { return LogInFailedSubject; } }

        void Awake()
        {
            GameServerConnection.PacketMethods[PacketID.LogInResult] += (Stream) =>
                {
                    PacketLogInResult Result = new PacketLogInResult();
                    Result.Serialize(Stream);
                    if (Result.Result != (byte)PacketLogInResult.ResultCode.Success)
                    {
                        LogInFailedSubject.OnNext((PacketLogInResult.ResultCode)Result.Result);
                        return;
                    }
                    LogInSuccessSubject.OnNext(Unit.Default);
                };
        }
    }
}
