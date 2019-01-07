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
const int maxn = 1010;
const double eps = 1e-5;
const double e = 2.718281828459;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string str;
    cin.get();
    getline(cin, str);
    int len = str.length();
    char maze[maxn][maxn];
    mem(maze, ' ');
    int all_c = ceil((double)len / (double)n);
    int cnt = 0;
    for (int i = all_c; i > 0; --i) {
        for (int j = 1; j <= n; ++j) {
            if (cnt >= len) {
                break;
            }
            else {
                maze[j][i] = str[cnt++];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= all_c; ++j) {
            cout << maze[i][j];
        }
        cout << endl;
    }
    return 0;
}
