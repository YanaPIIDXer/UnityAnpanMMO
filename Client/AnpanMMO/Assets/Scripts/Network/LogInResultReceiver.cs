using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using UniRx;
using Network.Packet;

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

        void Awake()
        {
            GameServerConnection.OnRecvPacket
                .Where((Data) => Data.Id == PacketID.LogInResult)
                .Subscribe((Data) =>
                {
                    PacketLogInResult Result = new PacketLogInResult();
                    Result.Serialize(Data.Stream);
                    if (Result.Result != (byte)PacketLogInResult.ResultCode.Success)
                    {
                        Debug.Log("LogIn Failed...");
                        return;
                    }
                    LogInSuccessSubject.OnNext(Unit.Default);
                });
        }
    }
}
