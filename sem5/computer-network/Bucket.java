import java.util.*;

public class Bucket {
	static void solution(int psize, int output) {
		int bsize = 512;
		if (psize > bsize) {
			System.out.println("Bucket overflow!");
		} else {
			while(psize > output) {
				System.out.println(output + " bytes outputted");
				psize = psize - output;
			}
		}
	}

	public static void main(String[] args) {
		int output, psize, n;

		Scanner r = new Scanner(System.in);
		Random rand = new Random();

		System.out.print("\nEnter the output rate: ");
		output = r.nextInt();
		System.out.print("\nEnter the no. of packets: ");
		n = r.nextInt();

		for(int i = 0; i < n; i++) {
			psize = rand.nextInt(1000);
			System.out.println("packet no. " + i + " packet size " + psize);
			solution(psize, output);
		}
	}
}
