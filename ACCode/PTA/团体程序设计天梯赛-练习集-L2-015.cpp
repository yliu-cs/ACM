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
#include <functional>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 51;
const double eps = 1e-5;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;

bool cmp(double a, double b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    double *res;
    res = new double[n];
    for (int i = 0; i < n; ++i) {
        double *a;
        a = new double[k];
        for (int j = 0; j < k; ++j) {
            cin >> a[j];
        }
        sort(a, a + k, cmp);
        double sum = 0;
        for (int j = 1; j < k - 1; ++j) {
            sum += a[j];
        }
        res[i] = sum / (k - 2);
    }
    sort(res, res + n, cmp);
    for (int i = n - m; i < n; ++i) {
        cout << setiosflags(ios::fixed) << setprecision(3) << res[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    return 0;
}
