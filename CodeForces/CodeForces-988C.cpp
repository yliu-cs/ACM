#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
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
    map<int, P> m;
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int n,s = 0;
        scanf("%d", &n);
        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[j]);
            s += a[j];
        }
        for (int j = 0; j < n; ++j) {
            int k = s - a[j];
            if (m.count(k)) {
                printf("YES\n%d %d\n%d %d", i + 1, j + 1, m[k].first + 1, m[k].second + 1);
                return 0;
            }
        }
        for (int j = 0; j < n; ++j) {
            m[s - a[j]] = mp(i, j);
        }
    }
    printf("NO\n");
    return 0;
}
