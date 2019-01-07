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
const int maxn = 1010;
const double eps = 1e-6;

struct coordinate {
    double x;
    double y;
}ac[maxn];

struct connect {
    int v;
    double dis;
};

int n, pre[maxn];
double d;
int Active_num;
int Active_num1, Active_num2;
char active;
bool Fix[maxn];
vector<connect> Adj[maxn];

void init() {
    for (int i = 0; i <= n; ++i) {
        pre[i] = i;
    }
    mem(Fix, 0);
}

int find(int x) {
    int r = x;
    while (pre[r] != r) {
        r = pre[r];
    }
    return r;
}

void join(int x, int y) {
    int xx = find(x);
    int yy = find(y);
    if (xx != yy) {
        pre[xx] = yy;
    }
}

void Get_Information() {
    cin >> n >> d;
    for (int i = 1;i <= n; ++i) {
        cin >> ac[i].x >> ac[i].y;
    }
}

double Cal_dis(coordinate a, coordinate b) {
    double dx = abs(a.x - b.x);
    double dy = abs(a.y - b.y);
    double temp = sqrt(pow(dx, 2.0) + pow(dy, 2.0));
    return temp;
}

void Deal_data() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i < j) {
                connect add;
                add.v = j;
                add.dis = Cal_dis(ac[i], ac[j]);
                Adj[i].push_back(add);
                add.v = i;
                Adj[j].push_back(add);
            }
        }
    }
}

void Work() {
    while (cin >> active) {
        if (active == 'O') {
            cin >> Active_num;
            Fix[Active_num] = 1;
            for (int i = 0; i < Adj[Active_num].size(); ++i) {
                if (Adj[Active_num][i].dis <= d && Fix[Adj[Active_num][i].v]) {
                    join(Active_num, Adj[Active_num][i].v);
                }
            }
        }
        else if (active == 'S') {
            cin >> Active_num1 >> Active_num2;
            if (find(Active_num1) == find(Active_num2)) {
                cout << "SUCCESS" << endl;
            }
            else {
                cout << "FAIL" << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Get_Information();
    Deal_data();
    init();
    Work();
    return 0;
}
