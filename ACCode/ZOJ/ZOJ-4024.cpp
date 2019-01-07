#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;

int t;
int n;
ll a[maxn];
bool flag;
bool ans;

int main() {
    //fropen("in.txt", "r", stdin);
    scanf("%d", &t);
    while (t--) {
        flag = 1;
        ans = 1;
        scanf("%d", &n);
        scanf("%lld", &a[0]);
        for (int i = 1; i < n; ++i) {
            scanf("%lld", &a[i]);
            if (a[i] == a[i - 1]) {
                ans = 0;
            }
            if (!ans) {
                continue;
            }
            if (flag) {
                if (a[i] < a[i - 1]) {
                    if (i == 1) {
                        ans = 0;
                    }
                    flag = 0;
                }
            }
            else {
                if (a[i] > a[i - 1]) {
                    ans = 0;
                }
            }
        }
        if (ans && !flag) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}

