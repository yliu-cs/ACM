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
    int t;
    cin >> t;
    while (t--) {
        double a, b, k;
        cin >> a >> b >> k;
        double ans = b / (a + b);
        cout << setiosflags(ios::fixed) << setprecision(3) << ans << endl;
    }
    return 0;
}
