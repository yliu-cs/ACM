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
const int maxn = 1e5+5;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    char s1[5], s2[10];
    cin >> s1 >> s2;
    if (!strcmp(s2, "week")) {
        if (n != 5 && n != 6) {
            cout << 52;
        }
        else {
            cout << 53;
        }
    }
    else {
        if (n <= 29) {
            cout << 12;
        }
        else if (n == 30) {
            cout << 11;
        }
        else {
            cout << 7;
        }
    }
    return 0;
}
