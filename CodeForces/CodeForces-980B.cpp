#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> p;
const int INF = 0x3f3f3f3f;
const int maxn = 1e2+5;
const int mod = 1e9+7;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

int n, k;
char ans[5][maxn];

int main() {
    //fre();
    scanf("%d%d", &n, &k);
    printf("YES\n");
    mem(ans, '.');
    if (k % 2) {
        ans[2][(n + 1) >> 1] = '#';
        k--;
        int temp = (n - 1) >> 1;
        while (k && temp > 1) {
            ans[2][temp] = '#';
            ans[2][(n + 1) - temp] = '#';
            temp--; k -= 2;
        }
        temp = 2;
        while (k) {
            ans[3][temp] = '#';
            ans[3][(n + 1) - temp] = '#';
            temp++; k-= 2;
        }
    }
    else {
        int temp = 2;
        while (k) {
            ans[2][temp] = '#';
            ans[3][temp] = '#';
            temp++; k -= 2;
        }
    }
    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
