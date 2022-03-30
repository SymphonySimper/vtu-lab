// |---------------------------------------------------------------------------------------------|
// | Using TCP/IP sockets, write a client - server program to make the client send the file name |
// | and to make the server send back the contents of the requested file if present.             |
// |---------------------------------------------------------------------------------------------|

import java.net.*;
import java.io.*;

public class TCPC {
	public static void main(String args[]) throws Exception {
		Socket sock = new Socket("127.0.0.1", 5000);
		System.out.print("Enter the file name: ");
		BufferedReader keyRead = new BufferedReader(new InputStreamReader(System.in));
		String fname = keyRead.readLine();

		OutputStream ostream = sock.getOutputStream();
		PrintWriter pwrite = new PrintWriter(ostream, true);
		System.out.println();
		pwrite.println(fname);

		InputStream istream = sock.getInputStream();
		BufferedReader socketRead = new BufferedReader(new InputStreamReader(istream));
		String str;
		while((str = socketRead.readLine()) != null)
			System.out.println(str);

		sock.close();
		pwrite.close();
		keyRead.close();
		socketRead.close();
	}
}

// |----------------------------|
// | Sample Output              |
// |----------------------------|
// | Enter the file name: hello |
// |                            |
// | Hello World!               |
// |----------------------------|
