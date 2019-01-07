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

int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    if (n == 1) {
        cout << m / 2;
    }
    else if (m == 1) {
        cout << n / 2;
    }
    else {
        int sm = n < m ? n : m;
        int la = n > m ? n : m;
        int ans = 0;
        ans += la * (sm / 2);
        if (sm % 2) {
            ans += la / 2;
        }
        cout << ans;
    }
    return 0;
}