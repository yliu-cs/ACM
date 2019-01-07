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
const int maxn = 100010;
const double eps = 1e-5;
const double e = 2.718281828459;

struct person {
    char sex;
    int mother_path;
    int father_path;
    person() {
        sex = 'M';
        mother_path = -1;
        father_path = -1;
    }
}people[maxn];

int n, m;
bool vis[maxn];

void Get_information() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int id;
        cin >> id;
        cin >> people[id].sex >> people[id].father_path >> people[id].mother_path;
        if (people[id].father_path != -1) {
            people[people[id].father_path].sex = 'M';
        }
        if (people[id].mother_path != -1) {
            people[people[id].mother_path].sex = 'F';
        }
    }
}

bool Judge(int a, int b) {
    mem(vis, 0);
    queue<int> a_ancestor[3];
    vis[a] = 1;
    if (people[a].father_path != -1) {
        a_ancestor[0].push(people[a].father_path);
        vis[people[a].father_path] = 1;
    }
    if (people[a].mother_path != -1) {
        a_ancestor[0].push(people[a].mother_path);
        vis[people[a].mother_path] = 1;
    }
    for (int i = 0; i <= 2; ++i) {
        while (!a_ancestor[i].empty()) {
            int temp_ancestor = a_ancestor[i].front();
            a_ancestor[i].pop();
            if (temp_ancestor == -1) {
                continue;
            }
            if (i < 2) {
                if (people[temp_ancestor].father_path != -1) {
                    a_ancestor[i + 1].push(people[temp_ancestor].father_path);
                    vis[people[temp_ancestor].father_path] = 1;
                }
                if (people[temp_ancestor].mother_path != -1) {
                    a_ancestor[i + 1].push(people[temp_ancestor].mother_path);
                    vis[people[temp_ancestor].mother_path] = 1;
                }
            }
            else {
                if (people[temp_ancestor].father_path != -1) {
                    vis[people[temp_ancestor].father_path] = 1;
                }
                if (people[temp_ancestor].mother_path != -1) {
                    vis[people[temp_ancestor].mother_path] = 1;
                }
            }
        }
    }
    queue<int> b_ancestor[4];
    if (vis[b]) {
        return 0;
    }
    if (vis[people[b].father_path]) {
        return 0;
    }
    else {
        b_ancestor[0].push(people[b].father_path);
    }
    if (vis[people[b].mother_path]) {
        return 0;
    }
    else {
        b_ancestor[0].push(people[b].mother_path);
    }
    for (int i = 0; i <= 2; ++i) {
        while (!b_ancestor[i].empty()) {
            int temp_ancestor = b_ancestor[i].front();
            b_ancestor[i].pop();
            if (temp_ancestor == -1) {
                continue;
            }
            if (people[temp_ancestor].father_path != -1) {
                if (vis[people[temp_ancestor].father_path]) {
                    return 0;
                }
                b_ancestor[i + 1].push(people[temp_ancestor].father_path);
            }
            if (people[temp_ancestor].mother_path != -1) {
                if (vis[people[temp_ancestor].mother_path]) {
                    return 0;
                }
                b_ancestor[i + 1].push(people[temp_ancestor].mother_path);
            }
        }
    }
    return 1;
}

void Ask_output() {
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int ask1, ask2;
        cin >> ask1 >> ask2;
        if (people[ask1].sex == people[ask2].sex) {
            cout << "Never Mind" << endl;
        }
        else {
            if (Judge(ask1, ask2)) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Get_information();
    Ask_output();
    return 0;
}
