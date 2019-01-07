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
    stack<int> sta;
    int n, k;
    cin >> n >> k;
    int a;
    cin >> a;
    sta.push(a);
    n--;
    while (n--) {
        int b;
        cin >> b;
        if (sta.empty()) {
            sta.push(b);
        }
        else {
            if (b - sta.top() <= k) {
                sta.push(b);
            }
            else {
                while (!sta.empty()) {
                    sta.pop();
                }
                sta.push(b);
            }
        }
    }
    int num = 0;
    while (!sta.empty()) {
        num++;
        sta.pop();
    }
    cout << num;
    return 0;
}
