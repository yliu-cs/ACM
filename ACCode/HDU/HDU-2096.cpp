#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 2600;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

int main(){
    //fre();
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a >= 100) {
            a %= 100;
        }
        if (b >= 100) {
            b %= 100;
        }
        int ans = a + b;
        if (ans >= 100) {
            ans %= 100;
        }
        cout << ans << endl;
    }
    return 0;
}
