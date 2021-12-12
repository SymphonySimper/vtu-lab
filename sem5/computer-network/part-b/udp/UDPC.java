// |----------------------------------------------------------------------------------------------|
// | Write a program on datagram socket for client/server to display the messages on client side, |
// | typed at the server side.                                                                    |
// |----------------------------------------------------------------------------------------------|

import java.io.*;
import java.net.*;

public class UDPC {
	public static void main(String[] args) {
		DatagramSocket skt;
		try {
			skt = new DatagramSocket();
			String msg = "network lab ";
			byte[] b = msg.getBytes();
			InetAddress host = InetAddress.getByName("127.0.0.1");
			int serverSocket = 6789;
			DatagramPacket request = new DatagramPacket(b, b.length, host, serverSocket);
			skt.send(request);
			byte[] buffer = new byte[1000];
			DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
			skt.receive(reply);
			System.out.println("Client received: " + new String(reply.getData()));
			skt.close();
		}
		catch(Exception ex) {
//			System.out.println(ex);
		}
	}
}

// |----------------------------------------|
// | Sample Output                          |
// |----------------------------------------|
// | Client received: lab server processed. |
// |----------------------------------------|
