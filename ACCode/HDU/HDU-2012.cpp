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

bool IsPrime[maxn];

void Prime() {
    mem(IsPrime, 1);
    IsPrime[1] = 0;
    for (ll i = 2; i < maxn; ++i) {
        if (IsPrime[i]) {
            for (ll j = i * i; j < maxn; j += i) {
                IsPrime[j] = 0;
            }
        }
    }
}

int main(){
    //fre();
    Prime();
    int x, y;
    while (~scanf("%d%d", &x, &y)) {
        if (x == 0 && y == 0) {
            break;
        }
        bool flag = 1;
        for (int n = x; n <= y; ++n) {
            int temp = n * n + n + 41;
            if (!IsPrime[temp]) {
                flag = 0;
            }
        }
        if (flag) {
            printf("OK\n");
        }
        else {
            printf("Sorry\n");
        }
    }
    return 0;
}
