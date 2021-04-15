using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Network;

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
        }
    }
}
