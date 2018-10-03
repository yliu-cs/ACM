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
    if (n == 1) {
        cout << 1 << endl << 1;
    }
    else if (n == 2) {
        cout << 1 << endl << 1;
    }
    else if (n == 3) {
        cout << 2 << endl << 1 << " " << 3;
    }
    else if (n == 4) {
        cout << 4 << endl << 2 << " " << 4 << " " << 1 << " " << 3;
    }
    else {
        cout << n << endl;
        cout << 1;
        for (int i = 3; i <= n; i += 2) {
            cout << " " << i;
        }
        for (int i = 2; i <= n; i += 2) {
            cout << " " << i;
        }
    }
    return 0;
}
