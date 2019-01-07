#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 2e2+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

// 直接模拟计算
int main() {
    //fre();
    int book[7] = {16, 7, 8, 1, 1, 2, 3};
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<char> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        bool flag11 = 0, flag12 = 0;
        for (auto it : a) {
            ans += book[it - 'A'];
            if (it == 'B') {
                flag11 = 1;
            }
            if (it == 'C') {
                flag12 = 1;
            }
        }
        if (!flag11 || !flag12) {
            if (ans > 1) {
                ans--;
            }
        }
        int m;
        cin >> m;
        vector<char> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        int res = 0;
        bool flag21 = 0, flag22 = 0;
        for (auto it : b) {
            res += book[it - 'A'];
            if (it == 'B' || it == 'C') {
                flag21 = 1;
            }
            if (it == 'C') {
                flag22 = 1;
            }
        }
        if (!flag21 || !flag22) {
            if (res > 1) {
                res--;
            }
        }
        if (ans == res) {
            cout << "tie" << endl;
        }
        else if (ans > res) {
            cout << "red" << endl;
        }
        else if (ans < res) {
            cout << "black" << endl;
        }
    }
    return 0;
}
