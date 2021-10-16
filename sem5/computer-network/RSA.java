// |-----------------------------------------------------------------------|
// | Write a program for simple RSA algorithm to encrypt and decrypt data. |
// |-----------------------------------------------------------------------|

import java.util.*;
import java.io.*;

public class RSA {
	public static int mul(int x,int y, int n) {
		int k = 1,j;

		for(j = 1; j <= y; j++)
			k = (k * x) % n;

		return k;
	}

	public static void main(String[] args) {
		String msg;
		int pt[] = new int[100];
		int ct[] = new int[100];
		int e, d, n, i;

		Scanner r = new Scanner(System.in);

		System.out.print("Enter the message to encrypt: ");
		msg = r.next();

		for(i = 0; i < msg.length(); i++)
			pt[i] = msg.charAt(i);

		n = 253; e = 13; d = 17;
		System.out.print("\nCypher text is: ");

		for(i = 0; i < msg.length(); i++)
			ct[i] = mul(pt[i], e, n);
		for(i = 0; i < msg.length(); i++)
			System.out.print(ct[i]);

		System.out.print("\nDecyrpted text is: ");

		for(i = 0; i < msg.length(); i++)
			pt[i] = mul(ct[i], d, n);
		for(i = 0; i < msg.length(); i++)
			System.out.print((char) pt[i]);
	}
}

// |------------------------------------|
// | Sample output                      |
// |------------------------------------|
// | Enter the message to encrypt: ssce |
// |                                    |
// | Cypher text is: 929266173          |
// | Decyrpted text is: ssce%           |
// |------------------------------------|
