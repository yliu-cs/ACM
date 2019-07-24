import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(new BufferedInputStream(System.in));
		while (scan.hasNext()) {
			BigInteger x = scan.nextBigInteger();
			BigInteger a = scan.nextBigInteger();
			BigInteger y = scan.nextBigInteger();
			BigInteger b = scan.nextBigInteger();
			BigInteger l = x.multiply(b), r = a.multiply(y);
			if (l.compareTo(r) < 0) {
				System.out.println("<");
			}
			else if (l.compareTo(r) = 0) {
				System.out.println("=");
			}
			else if (l.compareTo(r) > 0) {
				System.out.println(">");
			}
		}
	}
}
