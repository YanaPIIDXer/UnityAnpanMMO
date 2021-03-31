using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Network;

/// <summary>
/// 接続テストボタン
/// そのうち消す
/// </summary>
public class ConnectionTestButton : MonoBehaviour
{
    private ServerConnection Connection = new ServerConnection();

    /// <summary>
    /// ボタン押下時の処理
    /// </summary>
    public void ButtionAction()
    {
        if (Connection.IsConnected) { return; }
        if (!Connection.Connect("localhost", 1234))
        {
            Debug.Log("Connection Failed.");
            return;
        }
        Debug.Log("Connection Success!");
    }
}
