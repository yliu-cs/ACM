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

int t;

// 数据水
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int u = 1; u <= t; ++u) {
        double x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;
        double ask_x, ask_y;
        cin >> ask_x >> ask_y;
        double a, b, c;
        a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
        c = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
        double judge_x, judge_y;
        judge_y = (y1 + y2 + y3) / 3.0;
        judge_x = (x1 + x2 + x3) / 3.0;
        double judge_r = sqrt(pow(x2 - judge_x, 2) + pow(y2 - judge_y, 2));
        double distance = sqrt(pow(judge_x - ask_x, 2) + pow(judge_y - ask_y, 2));
        cout << "Case #" << u << ": ";
        if (distance <= judge_r) {
            cout << "Danger" << endl;
        }
        else {
            cout << "Safe" << endl;
        }
    }
    return 0;
}
