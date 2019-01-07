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
const int maxn = 3e3+5;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    if (n % 2) {
        if (k > (n / 2 + 1)) {
            k -= n / 2 + 1;
            cout << 2 * k << endl;
        }
        else {
            cout << 1 + 2 * (k - 1) << endl;
        }
    }
    else {
        if (k > (n / 2)) {
            k -= n / 2;
            cout << 2 * k << endl;
        }
        else {
            cout << 1 + 2 * (k - 1) << endl;
        }
    }
    return 0;
}