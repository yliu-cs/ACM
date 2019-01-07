#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e2+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

int n, k;
int a[maxn];
int cnt;
set<int> vis;
vector<int> ans;

int main(){
    //fre();
    vis.clear(); ans.clear();
    cnt = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (cnt < k) {
            if (vis.count(a[i]) == 0) {
                vis.insert(a[i]);
                cnt++;
                ans.pb(i);
            }
        }
    }
    if (cnt >= k) {
        printf("YES\n");
        for (auto it : ans) {
            printf("%d ", it);
        }
    }
    else {
        printf("NO\n");
    }
    return 0;
}
