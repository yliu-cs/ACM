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
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;

int n;
bool ans[maxn];

void work() {
    mem(ans, 1);
    for (long long i = 2; i < maxn; ++i) {
        for (long long j = i; j < maxn; j += i) {
            ans[j] = !ans[j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    work();
    while (cin >> n) {
        cout << ans[n] << endl;
    }
    return 0;
}
