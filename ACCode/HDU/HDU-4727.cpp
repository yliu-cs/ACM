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
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double e = 2.718281828459;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int u = 1; u <= t; ++u) {
		// 此处ans一定要初始化为1
		// 因为可能第一个人错之后全错
        int n, ans = 1;
        cin >> n;
        ll a, b;
        cin >> a;
        for (int i = 2; i <= n; ++i) {
            cin >> b;
            if (b != a + 1) {
                ans = i;
            }
            a = b;
        }
        cout << "Case #" << u << ": " << ans << endl;
    }
    return 0;
}
