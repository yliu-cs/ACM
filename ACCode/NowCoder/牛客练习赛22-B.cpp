#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 102;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}
 
int main() {
    //fre();
    int a[3];
    bool b = 0;
    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            b = 1;
        }
    }
    int ans = 0;
    if (b) {
        if (a[0] == 1) {
            if (a[1] == 1) {
                if (a[2] == 1) {
                    ans += a[0] + a[1] + a[2];
                }
                else {
                    ans += (a[0] + a[1]) * a[2];
                }
            }
            else {
                if (a[2] == 1) {
                    ans += a[0] + a[1] + a[2];
                }
                else {
                    ans += (a[0] + a[1]) * a[2];
                }
            }
        }
        else {
            if (a[1] == 1) {
                if (a[2] == 1) {
                    ans += a[0] * (a[1] + a[2]);
                }
                else {
                    if (a[0] > a[2]) {
                        ans += a[0] * (a[1] + a[2]);
                    }
                    else {
                        ans += (a[0] + a[1]) * a[2];
                    }
                }
            }
            else {
                if (a[2] == 1) {
                    ans += a[0] * (a[1] + a[2]);
                }
                else {
                    ans += a[0] * a[1] * a[2];
                }
            }
        }
    }
    else {
        ans += a[0] * a[1] * a[2];
    }
    cout << ans << endl;
    return 0;
}
