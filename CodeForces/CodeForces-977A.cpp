#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <set>
#include <map>
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
void fre() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

ll n, k;

ll work(ll x) {
    ll temp = x % 10;
    if (temp == 0) {
        return x / 10;
    }
    else {
        return x - 1;
    }
}

int main() {
    //fre();
    scanf("%I64d %I64d", &n, &k);
    for (int i = 0; i < k; ++i) {
        n = work(n);
    }
    printf("%I64d", n);
    return 0;
}
