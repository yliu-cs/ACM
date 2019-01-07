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

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, n;
    cin >> a >> b >> n;
    while (1) {
        if (n >= gcd(a, n)) {
            n -= gcd(a, n);
        }
        else {
            cout << 1;
            break;
        }
        if (n >= gcd(b, n)) {
            n -= gcd(b, n);
        }
        else {
            cout << 0;
            break;
        }
    }
    return 0;
}
