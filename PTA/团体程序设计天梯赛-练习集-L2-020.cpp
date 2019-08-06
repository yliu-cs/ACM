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
    vector<int> path[maxn];
    double magic[maxn];
    int big[maxn];
    ll n;
    double z, r;
    cin >> n >> z >> r;
    if (n == 1) {
        int k, a;
        cin >> k >> a;
        cout << z * a;
    }
    else {
        magic[0] = z;
        double res = 0;
        for (int i = 0; i < n; i++) {
            big[i] = 1;
            int k;
            cin >> k;
            if (k == 0) {
                ll a;
                cin >> a;
                big[i] = a;
            }
            else {
                while (k--) {
                    int a;
                    cin >> a;
                    path[i].push_back(a);
                }
            }
        }
        queue<int> que;
        for (int i = 0; i < path[0].size(); ++i) {
            int u = path[0][i];
            magic[u] = magic[0] * ((100 - r) / 100.0);
            que.push(u);
        }
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            for (int i = 0; i < path[x].size(); ++i) {
                int u = path[x][i];
                magic[u] = magic[x] * ((100 - r) / 100);
                que.push(u);
            }
            if (big[x] != 1) {
                magic[x] = magic[x] * big[x];
                res += magic[x];
            }
        }
        cout << (int)res;
    }
    return 0;
}
