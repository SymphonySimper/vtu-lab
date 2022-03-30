// |---------------------------------------------------------------------------------------------|
// | Using TCP/IP sockets, write a client - server program to make the client send the file name |
// | and to make the server send back the contents of the requested file if present.             |
// |---------------------------------------------------------------------------------------------|

import java.net.*;
import java.io.*;

public class TCPS {
	public static void main(String args[]) throws Exception {
		ServerSocket sersock = new ServerSocket(5000);
		System.out.println("Server ready for connection");
		Socket sock = sersock.accept();

		InputStream istream = sock.getInputStream();
		BufferedReader fileRead = new BufferedReader(new InputStreamReader(istream));
		String fname = fileRead.readLine();

		BufferedReader contentRead = new BufferedReader(new FileReader(fname));
		OutputStream ostream = sock.getOutputStream();
		PrintWriter pwrite = new PrintWriter(ostream, true);
		String str;
		while((str = contentRead.readLine()) != null)
			pwrite.println(str);
		System.out.println("Connection is successful");

		sock.close();
		sersock.close();
		pwrite.close();
		fileRead.close();
		contentRead.close();
	}
}

// |-----------------------------|
// | Sample Output               |
// |-----------------------------|
// | Server ready for connection |
// | Connection is successful    |
// |-----------------------------|
