#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double e = 2.718281828459;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int a[maxn], sum[maxn];
    sum[0] = 0;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        int left = 1, ans = n + 1;
        for (int i = 1; i <= n; ++i) {
            if (sum[i] - sum[left - 1] < m) {
                continue;
            }
            while (sum[i] - sum[left] >= m) {
                left++;
            }
            ans = ans < i - left + 1 ? ans : i - left + 1;
        }
        ans = ans == n + 1 ? 0 : ans;
        cout << ans << endl;
    }
    return 0;
}
