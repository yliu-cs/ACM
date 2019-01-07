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
const double pi = asin(1.0)*2;
const double e = 2.718281828459;

int cnt_1[26];
int cnt_2[26];
string str1, str2;
int change;
bool vis[26];
priority_queue<int> que1;
priority_queue<int> que2;

bool judge() {
    mem(cnt_1, 0);
    mem(cnt_2, 0);
    for (int i = 0; str1[i] != '\0'; ++i) {
        cnt_1[str1[i] - 'A']++;
    }
    for (int i = 0; str2[i] != '\0'; ++i) {
        cnt_2[str2[i] - 'A']++;
    }
    for (int i = 0; i < 26; ++i) {
        if (cnt_1[i]) {
            que1.push(cnt_1[i]);
        }
        if (cnt_2[i]) {
            que2.push(cnt_2[i]);
        }
    }
    while (!que1.empty() && !que2.empty()) {
        int temp1 = que1.top(), temp2 = que2.top();
        if (temp1 != temp2) {
            while (!que1.empty()) {
                que1.pop();
            }
            while (!que2.empty()) {
                que2.pop();
            }
            return 0;
        }
        que1.pop();
        que2.pop();
    }
    if (!que1.empty()) {
        que1.pop();
        return 0;
    }
    if (!que2.empty()) {
        que2.pop();
        return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (getline(cin, str1)) {
        getline(cin, str2);
        if (judge()) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}