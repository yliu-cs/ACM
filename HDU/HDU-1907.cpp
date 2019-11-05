#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

int t;
int n;
int a[maxn];
int temp;
int cnt;

// 尼姆博弈，异或判断是否为0
int main(){
    //fre();
    scanf("%d", &t);
    while (t--) {
        temp = 0;
        cnt = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            temp ^= a[i];
            if (a[i] > 1) {
                cnt++;
            }
        }
        if ((temp == 0 && cnt > 1) || (n % 2 && cnt == 0)) {
            printf("Brother\n");
        }
        else {
            printf("John\n");
        }
    }
    return 0;
}
