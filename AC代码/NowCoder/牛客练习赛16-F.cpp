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
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
 
ll n, d;
ll a[maxn];
ll sum;
 
int main() {
    scanf("%lld %lld", &n, &d);
    sum = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    for (ll i = 1; i <= n; ++i) {
        int pos = lower_bound(a + 1, a + i, a[i] - d) - a;
        if (i > pos - 1) {
            sum += (i - pos) * (i - pos - 1) / 2;
        }
    }
    printf("%lld", sum);
    return 0;
}
