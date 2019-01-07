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
    string sta1, sta2;
    cin >> sta1 >> sta2;
    int n;
    cin >> n;
    cout << sta1 << " " << sta2 << endl;
    while (n--) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 == sta1) {
            sta1 = s2;
        }
        if (s1 == sta2) {
            sta2 = s2;
        }
        cout << sta1 << " " << sta2 << endl;
    }
    return 0;
}
