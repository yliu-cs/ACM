#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

int m, n, p;
// 可以取走的石子个数，这道题目是斐波那契数列
int f[17]={1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597};
// 0~n的SG值
int SG[maxn];
// mex{}
int HASH[maxn];

// SG打表
void getSG() {
    mem(SG, 0);
    for (int i = 1; i < maxn; ++i) {
        mem(HASH, 0);
        for (int j = 1; f[j] <= i; ++j) {
            HASH[SG[i - f[j]]] = 1;
        }
        for (int j = 0; j < maxn; ++j) {
            if (HASH[j] == 0) {
                SG[i] = j;
                break;
            }
        }
    }
}

int main() {
    //fre();
    getSG();
    while (~scanf("%d%d%d", &m, &n, &p), m + n + p) {
        if (SG[m] ^ SG[n] ^ SG[p]) {
            printf("Fibo\n");
        }
        else {
            printf("Nacci\n");
        }
    }
    return 0;
}
