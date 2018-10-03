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

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num[12], k, sum = 0;
    cin >> k;
    for (int i = 0; i < 12; ++i) {
        cin >> num[i];
        sum += num[i];
    }
    if (sum < k) {
        cout << -1;
    }
    else if (k == 0) {
        cout << 0;
    }
    else {
        sort(num, num + 12, cmp);
        int res = 0, count = 0;
        for (int i = 0; i < 12; ++i) {
            res += num[i];
            count++;
            if (res >= k) {
                break;
            }
        }
        cout << count;
    }
    return 0;
}
