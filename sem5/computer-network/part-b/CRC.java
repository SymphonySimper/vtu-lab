// |---------------------------------------------------------------------|
// | Write a program for error detecting code using CRC-CCITT (16-bits). |
// |---------------------------------------------------------------------|

import java.util.*;
import java.io.*;

public class CRC {
	char t[] = new char[200];
	char cs[] = new char[200];
	char g[] = new char[200];
	int a, e, c;

	void xor() {
		for (int i = 1; i < 17; i++)
			cs[i]=((cs[i] == g[i]) ? '0' : '1');
	}

	void crc() {
		for(e = 0; e < 17; e++)
			cs[e] = t[e];

		do {
			if (cs[0] == '1')
				xor();

			for(c = 0; c < 16; c++)
				cs[c] = cs[c + 1];
			cs[c] = t[e++];
		} while (e <= a + 16);
	}

	void operation() {
		Scanner r = new Scanner(System.in);
		String msg;

		String gs="10001000000100001";
		for (int i = 0; i < gs.length(); i++)
			g[i] = gs.charAt(i);

		System.out.print("Enter the polynomial: ");
		msg = r.next();
		for (int i = 0; i < msg.length(); i++)
			t[i] = msg.charAt(i);

		System.out.print("\nGenerating polynomial is: ");
		for (int i = 0; i < gs.length(); i++)
			System.out.print(g[i]);

		a = msg.length();
		for (e = a; e < a + 16; e++)
			t[e] = '0';
		System.out.print("\nModified message is: ");
		for (int i = 0; i < msg.length() + 16; i++)
			System.out.print(t[i]);

		crc();
		System.out.print("\nChecksum is: ");
		for (int i = 0; i < 16; i++)
			System.out.print(cs[i]);
		for(e = a; e < a + 16; e++)
			t[e] = cs[e - a];

		System.out.print("\nFinal codeword is: ");
		for (int i = 0; i < a + 16; i++)
			System.out.print(t[i]);

		System.out.print("\n\nTest error detection 0(yes)/1(no): ");
		e = r.nextInt();
		if (e == 0) {
			System.out.print("Enter the position where error is to be inserted: ");
			e = r.nextInt();
			t[e] = (t[e] == '0') ? '1' : '0';

			System.out.print("\nErrornous data: ");
			for (int i = 0; i < a + 16; i++)
				System.out.print(t[i]);
		}

		crc();
		for (e = 0; (e < 16) && (cs[e] != '1'); e++);
		if (e < 16)
			System.out.println("\nError detected");
		else
			System.out.println("No error detected");
	}

	public static void main(String[] args) {
		CRC ob = new CRC();
		ob.operation();
	}
}

// |-----------------------------------------------------|
// | Sample Output                                       |
// |-----------------------------------------------------|
// | Enter the polynomial: 1011101                       |
// | Generating polynomial is: 10001000000100001         |
// | Modified message is: 10111010000000000000000        |
// | Checksum is: 1000101101011000                       |
// | Final codeword is: 10111011000101101011000          |
// |                                                     |
// | Test error detection 0(yes)/1(no): 0                |
// | Enter the position where error is to be inserted: 1 |
// |                                                     |
// | Errornous data: 11111011000101101011000             |
// | Error detected                                      |
// |-----------------------------------------------------|
// | Enter the polynomial: 1011101                       |
// |                                                     |
// | Generating polynomial is: 10001000000100001         |
// | Modified message is: 10111010000000000000000        |
// | Checksum is: 1000101101011000                       |
// | Final codeword is: 10111011000101101011000          |
// |                                                     |
// | Test error detection 0(yes)/1(no): 1                |
// | No error detected                                   |
// |-----------------------------------------------------|
