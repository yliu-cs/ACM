#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 11;
const double eps = 1e-5;
const double e = 2.718281828459;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str1, str2;
    while (cin >> str1 >> str2) {
        int a[maxn], b[maxn];
        mem(a, 0);
        mem(b, 0);
        int lenA = str1.length(), lenB = str2.length();
        int cnt = 0;
        for (int i = lenA - 1; i >= 0; --i) {
            a[cnt++] = str1[i] - '0';
        }
        cnt = 0;
        for (int i = lenB - 1; i >= 0; --i) {
            b[cnt++] = str2[i] - '0';
        }
        int len = lenA > lenB ? lenA : lenB;
        int c[maxn];
        for (int i = 0; i < len; ++i) {
            c[i] = a[i] + b[i];
            if (c[i] >= 10) {
                c[i] %= 10;
            }
        }
        bool flag = 1;
        for (int i = len - 1; i >= 0; --i) {
            if (c[i] != 0 || !flag) {
                cout << c[i];
                flag = 0;
            }
        }
        if (flag) {
            cout << 0;
        }
        cout << endl;
    }
    return 0;
}
