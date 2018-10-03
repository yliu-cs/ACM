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

double a, b;

double Distance(double x, double y) {
    return sqrt(pow(a - x, 2) + pow(b - y, 2));
}

bool cmp(double a, double b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    int n;
    cin >> n;
    double *num;
    num = new double[n];
    for (int i = 0; i < n; ++i) {
        double x, y, v;
        cin >> x >> y >> v;
        num[i] = Distance(x, y) / v;
    }
    sort(num, num + n, cmp);
    cout << setiosflags(ios::fixed) << setprecision(20) << num[0];
    return 0;
}
