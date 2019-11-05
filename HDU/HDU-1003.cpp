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

int num[maxn];
int maxsum[maxn];

int find_left(int x) {
    int sum = 0, ans = INF;
    for (int i = x; i >= 1; --i) {
        sum += num[i];
        if (sum == maxsum[x]) {
            if (i < ans) {
                ans = i;
            }
        }
    }
    return ans;
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    maxsum[0] = 0;
    int t;
    cin >> t;
    for (int Case = 1; Case <= t; ++Case) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
            maxsum[i] = max(maxsum[i - 1] + num[i], num[i]);
        }
        int ans = -INF, right = 1, left = 1;
        for (int i = 1; i <= n; ++i) {
            if (maxsum[i] > ans) {
                ans = maxsum[i];
                right = i;
                left = find_left(i);
            }
        }
        cout << "Case " << Case << ":" << endl;
        cout << ans << " " << left << " " << right << endl;
        if (Case != t) {
            cout << endl;
        }
    }
    return 0;
}
