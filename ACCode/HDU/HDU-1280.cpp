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

struct ac {
    int num;
    bool operator < (const ac &a) const {
        return a.num < num;
    }
};

int n, m;
int a[maxn], b[maxn];
int ans[maxn];
priority_queue<ac> que;

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    while (cin >> n >> m) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(a, a + n, cmp);
        sort(b, b + n, cmp);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!que.empty()) {
                if (a[i] + b[0] < que.top().num && cnt >= m) {
                    break;
                }
            }
            for (int j = i; j < n; ++j) {
                if (i != j) {
                    if (!que.empty()) {
                        if (a[i] + b[j] < que.top().num && cnt >= m) {
                            break;
                        }
                    }
                    if (!que.empty() && cnt >= m) {
                        ac temp = que.top();
                        if (a[i] + b[j] > temp.num) {
                            que.push(ac {a[i] + b[j]});
                            que.pop();
                        }
                    }
                    else {
                        que.push(ac {a[i] + b[j]});
                        cnt++;
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            ans[i] = que.top().num;
            que.pop();
        }
        cout << ans[m - 1];
        for (int i = m - 2; i >= 0; --i) {
            cout << " " << ans[i];
        }
        cout << endl;
        while (!que.empty()) {
            que.pop();
        }
    }
    return 0;
}
