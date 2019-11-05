import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static BigInteger Cal1(BigInteger n, BigInteger a, BigInteger b) {
        return (n.pow(3).multiply(b)).add((n.pow(2)).multiply(n.subtract(BigInteger.valueOf(1))).multiply(a));
    }

    public static BigInteger Cal2(BigInteger n, BigInteger a, BigInteger b) {
        if (n.equals(BigInteger.valueOf(0))) return BigInteger.valueOf(0);
        BigInteger ck = n.divide(BigInteger.valueOf(2));
        BigInteger ans1 = BigInteger.valueOf(18).multiply((n.divide(BigInteger.valueOf(2))).pow(2)).multiply(a);
        if (ck.mod(BigInteger.valueOf(2)).equals(BigInteger.valueOf(0))) {
            BigInteger ret1 = ans1.add(BigInteger.valueOf(7).multiply(Cal1(ck, a, b)));
            BigInteger ret2 = ans1.add(BigInteger.valueOf(7).multiply(Cal2(ck, a, b)));
            if (ret1.compareTo(ret2) < 0) return ret1;
            else return ret2;
        }
        else return ans1.add(BigInteger.valueOf(7).multiply(Cal1(ck, a, b)));
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int t = scan.nextInt();
        for (int cas = 1; cas <= t; ++cas) {
            BigInteger n = scan.nextBigInteger();
            BigInteger a = scan.nextBigInteger();
            BigInteger b = scan.nextBigInteger();

            BigInteger ans1 = Cal1(n, a, b);
            if (n.equals(BigInteger.valueOf(1))) {
                System.out.println(ans1.mod(BigInteger.valueOf(1000000007)));
                continue;
            }
            BigInteger ans2 = Cal2(n, a, b);
            BigInteger ans;
            if (ans1.compareTo(ans2) < 0) ans = ans1;
            else ans = ans2;
            System.out.println(ans.mod(BigInteger.valueOf(1000000007)));
        }
    }
}