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

int judge(char x) {
    if (x >= 'A' && x <= 'Z') {
        return 0;
    }
    if (x >= 'a' && x <= 'z') {
        return 1;
    }
    if (x >= '0' && x <= '9') {
        return 2;
    }
    if (x == '~' || x == '!' || x == '@' || x == '#' || x == '$' || x == '%' || x == '^') {
        return 3;
    }
    return 4;
}

// 模拟
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        int len = str.length();
        if (len < 8 || len > 16) {
            cout << "NO" << endl;
            continue;
        }
        bool flag[5];
        mem(flag, 0);
        for (int i = 0; str[i] != '\0'; ++i) {
            flag[judge(str[i])] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < 4; ++i) {
            if (flag[i]) {
                cnt++;
            }
        }
        if (flag[4]) {
            cout << "NO" << endl;
        }
        else {
            if (cnt >= 3) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
