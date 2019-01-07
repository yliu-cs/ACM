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
    ll n, sum = 1;
    cin >> n;
    n++;
    bool flag = 0;
    while (!flag) {
        ll Judge = n;
        while (Judge) {
            if (abs(Judge % 10) == 8) {
                flag = 1;
                break;
            }
            Judge /= 10;
            flag = 0;
        }
        if (!flag) {
            n++;
            sum++;
        }
    }
    cout << sum;
    return 0;
}
