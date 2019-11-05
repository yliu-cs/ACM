#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int a;
        cin >> a;
        int Num[10];
        memset(Num, 0, sizeof(Num));
        Num[0] = a % 2;
        a -= a % 2;
        int p = 1;
        while (a) {
            Num[p] = a % (p + 2);
            a -= a % (p + 2);
            a /= (p + 2);
            p++;
        }
        for (int i = p - 1;i >= 0;--i) {
            while (Num[i]) {
                cout << i;
                Num[i]--;
            }
        }
        cout << endl;
    }
    return 0;
}
