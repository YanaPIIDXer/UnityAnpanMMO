using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Network;
using Network.Packet;

namespace UI
{
    /// <summary>
    /// ログインボタン
    /// </summary>
    public class LogInButton : MonoBehaviour
    {
        public void OnPressed()
        {
            if (GameServerConnection.Instance.IsConnected) { return; }
            if (!GameServerConnection.Instance.Connect())
            {
                Debug.Log("LogIn Failed...");
                return;
            }
            PacketLogInRequest Request = new PacketLogInRequest();
            GameServerConnection.Instance.SendPacket(Request);
        }
    }
}
