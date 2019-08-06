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
    char s1[110], s2[110];
    int res[110];
    cin >> s1 >> s2;
    int len = strlen(s1);
    for (int i = 0; i < len; ++i) {
        if (s1[i] == s2[i]) {
            res[i] = 0;
        }
        else {
            res[i] = 1;
        }
        cout << res[i];
    }
    return 0;
}