import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static int maxn = 10005;
    public static boolean IsPrime [] = new boolean[maxn];
    public static int Tot;
    public static BigInteger Prime [] = new BigInteger[maxn];

    public static void main(String[] agrs) {
        Tot = 0;
        for (int i = 0; i < maxn; ++i) {
            IsPrime[i] = true;
        }
        for (int i = 2; i < maxn; ++i) {
            if (IsPrime[i] == true) {
                Prime[Tot++] = BigInteger.valueOf(i);
                for (int j = i * i; j < maxn; j += i) {
                    IsPrime[j] = false;
                }
            }
        }

        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        for (int Case = 1; Case <= T; ++Case) {
            BigInteger N = cin.nextBigInteger();
            BigInteger Book = BigInteger.valueOf(1);
            BigInteger Up = BigInteger.valueOf(1);
            BigInteger Down = BigInteger.valueOf(1);
            for (int i = 0; i < Tot; ++i) {
                Book = Book.multiply(Prime[i]);
                if (Book.compareTo(N) > 0) {
                    break;
                }
                Up = Up.multiply(Prime[i]);
                Down = Down.multiply(Prime[i].add(BigInteger.valueOf(1)));
            }
            BigInteger Gcd = Up.gcd(Down);
            Up = Up.divide(Gcd);
            Down = Down.divide(Gcd);
            System.out.println(Up + "/" + Down);
        }
    }
}
