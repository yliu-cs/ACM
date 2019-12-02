import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static char Get(int x) {
        if (x >= 0 && x <= 9) {
            return (char)(x + '0');
        }
        else if (x >= 10 && x <= 35) {
            return (char)(x - 10 + 'A');
        }
        else {
            return (char)(x - 36 + 'a');
        }
    }

    public static int Get(char x) {
        if (x >= '0' && x <= '9') {
            return x - '0';
        }
        else if (x >= 'A' && x <= 'Z') {
            return x - 'A' + 10;
        }
        else {
            return x - 'a' + 36;
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        BigInteger x = scan.nextBigInteger(), y = scan.nextBigInteger();
        String s = scan.next();
        BigInteger num = BigInteger.valueOf(0);
        for (int i = 0; i < s.length(); ++i) {
            num = num.multiply(x).add(BigInteger.valueOf(Get(s.charAt(i))));
        }
        ArrayList<Character> ans = new ArrayList<Character>();
        while (!num.equals(BigInteger.valueOf(0))) {
            ans.add(Get(num.mod(y).intValue()));
            num = num.divide(y);
        }
        if (ans.isEmpty()) {
            ans.add('0');
        }
        for (int i = ans.size() - 1; i >= 0; --i) {
            System.out.print(ans.get(i));
        }
        System.out.println();
    }
}
