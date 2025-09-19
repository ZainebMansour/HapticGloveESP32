using System.Net;
using System.Net.Sockets;
using System.Text;
using UnityEngine;

public class UDPReceiver : MonoBehaviour {
    UdpClient udp;
    public int port = 4210;
    public Transform index1, index2, index3;

    void Start() {
        udp = new UdpClient(port);
    }

    void Update() {
        if (udp.Available > 0) {
            IPEndPoint remoteEP = new IPEndPoint(IPAddress.Any, 0);
            byte[] data = udp.Receive(ref remoteEP);
            string message = Encoding.ASCII.GetString(data);

            string[] parts = message.Split(',');
            if (parts.Length == 5) {
                float indexValue = Mathf.InverseLerp(700, 2000, int.Parse(parts[1])); 
                index1.localRotation = Quaternion.Euler(indexValue * 60f, 0, 0);
                index2.localRotation = Quaternion.Euler(indexValue * 60f, 0, 0);
                index3.localRotation = Quaternion.Euler(indexValue * 60f, 0, 0);
            }
        }
    }
}
