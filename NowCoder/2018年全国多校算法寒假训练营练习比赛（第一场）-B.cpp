#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    int n;
    while (cin >> n) {
        int *s,*t,*x;
        s = new int[n];
        t = new int[n];
        x = new int[n];
        for (int i = 0;i < n;++i) {
            x[i] = 0;
            cin >> s[i] >> t[i];
            if (t[i] == 1 || t[i] == 2) {
                cin >> x[i];
            }
        }
        int flag = 0;
        long long Sum = 0;
        for (int i = 0;i < n - 1;++i) {
            bool emm = 1;
            if (s[i] > s[i + 1]) {
                int book = 0;
                for (int j = i;j >= flag;j--) {
                    if (t[j] == 1) {
                        Sum += x[j];
                    }
                    else if (t[j] == 2) {
                        book = j - flag + 1;
                        Sum += book * x[j];
                    }
                    else if (t[j] == 3) {
                        break;
                    }
                    else if (t[j] == 4) {
                        j--;
                    }
                }
                flag = i + 1;
            }
            if (i == n - 2) {
                int book = 0;
                for (int j = i + 1;j >= flag;j--) {
                    if (t[j] == 1) {
                        Sum += x[j];
                    }
                    else if (t[j] == 2) {
                        book = j - flag + 1;
                        Sum += book * x[j];
                    }
                    else if (t[j] == 3) {
                        break;
                    }
                    else if (t[j] == 4) {
                        j--;
                    }
                }
            }
        }
        if (n == 1) {
            if (t[0] == 1 || t[0] == 2) {
                Sum += x[0];
            }
        }
        cout << Sum << endl;
    }
    return 0;
}
