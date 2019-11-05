#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 5e3+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

int n;
int a[maxn];
int p[maxn];
int ans[maxn];
bool vis[maxn];
int len;

int main() {
    //fre();
    mem(ans, 0);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        for (int j = 2; j * j <= abs(a[i]); ++j) {
            while (a[i] % (j * j) == 0) {
                a[i] /= (j * j);
            }
        }
        p[i] = a[i];
    }
    sort(p, p + n);
    len = unique(p, p + n) - p;
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(p, p + len, a[i]) - p;
    }
    for (int i = 0; i < n; ++i) {
        mem(vis, 0);
        int cnt = 0;
        bool zero = 0;
        for (int j = i; j < n; ++j) {
            if (!vis[a[j]]) {
                vis[a[j]] = 1;
                cnt++;
            }
            if (p[a[j]] == 0) {
                zero = 1;
            }
            ans[max(1, cnt - zero)]++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}
