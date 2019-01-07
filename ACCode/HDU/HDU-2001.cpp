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
const double e = 2.718281828459;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    double x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        cout << setiosflags(ios::fixed) << setprecision(2) << sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) << endl;
    }
    return 0;
}
