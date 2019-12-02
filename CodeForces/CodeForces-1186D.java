import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        boolean[] flag = new boolean[n];
        for (int i = 0; i < n; ++i) {
            flag[i] = false;
        }
        int[] a = new int[n];
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            String s = scan.next();
            String[] buf = new String[2];
            buf = s.split("\\.");
            boolean f = true;
            for (int j = 0; j < buf[1].length(); ++j) {
                if (buf[1].charAt(j) != '0') {
                    f = false;
                }
            }
            if (f == true) {
                flag[i] = true;
            }
            a[i] = Integer.valueOf(buf[0]);
            if (buf[0].charAt(0) == '-' && flag[i] != true) {
                a[i] -= 1;
            }
            sum += a[i];
        }
        for (int i = 0; i < n && sum != 0; ++i) {
            if (flag[i] == true) {
                continue;
            }
            a[i] += 1;
            sum += 1;
        }
        for (int i = 0; i < n; ++i) {
            System.out.println(a[i]);
        }
    }
}
