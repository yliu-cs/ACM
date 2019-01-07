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
#define _USE_MATH_DEFINES
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;

// 闰年判断
bool leap_year(int x) {
    if (x % 100 != 0 && x % 4 == 0) {
        return 1;
    }
    if (x  % 100 == 0 && x % 400 == 0) {
        return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
	// 每个月的天数
    int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string str;
    while (cin >> str) {
        int year = 0, month = 0, day = 0;
        int book = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == '/') {
                book = i;
                break;
            }
            year = year * 10 + str[i] - '0';
        }
        for (int i = book + 1; i < str.length(); ++i) {
            if (str[i] == '/') {
                book = i;
                break;
            }
            month = month * 10 + str[i] - '0';
        }
        for (int i = book + 1; i < str.length(); ++i) {
            day = day * 10 + str[i] - '0';
        }
        int ans = 0;
        for (int i = 1; i < month; ++i) {
            ans += a[i];
        }
        if (month > 2 && leap_year(year)) {
            ans++;
        }
        ans += day;
        cout << ans << endl;
    }
    return 0;
}
