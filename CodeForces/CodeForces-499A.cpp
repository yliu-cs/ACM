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
    int n, x, temp = 1, sum = 0;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        int sta, end;
        cin >> sta >> end;
        if (sta == temp) {
            sum += end - sta + 1;
            temp = end + 1;
        }
        else if (sta > temp) {
            while (temp + x <= sta) {
                temp += x;
            }
            sum += end - temp + 1;
            temp = end + 1;
        }
    }
    cout << sum;
    return 0;
}
