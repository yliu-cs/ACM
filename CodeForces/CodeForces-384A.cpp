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
    if (n % 2 == 0) {
        cout << n / 2 * n << endl;
    }
    else {
        cout << pow(n / 2, 2) + pow(n / 2 + 1, 2) << endl;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if ((i + j) % 2 == 0) {
                cout << "C";
            }
            else {
                cout << ".";
            }
        }
        if (i != n) {
            cout << endl;
        }
    }
    return 0;
}
