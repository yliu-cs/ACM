#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    int len = str.length();
    int num = 0;
    double res = 0.0;
    if (str[0] == '-') {
        for (int i = 1; i < len; ++i) {
            if (str[i] - '0' == 2) {
                num++;
            }
        }
        res = (double)num / (double)(len - 1.0);
        res *= 1.5;
        if ((str[len - 1] - '0') % 2 == 0) {
            res *= 2;
        }
        cout << setiosflags(ios::fixed) << setprecision(2) << res * 100 << "%";
    }
    else {
        for (int i = 0; i < len; ++i) {
            if (str[i] - '0' == 2) {
                num++;
            }
        }
        res = (double)num / (double)len;
        if ((str[len - 1] - '0') % 2 == 0) {
            res *= 2;
        }
        cout << setiosflags(ios::fixed) << setprecision(2) << res * 100 << "%";
    }
    return 0;
}
