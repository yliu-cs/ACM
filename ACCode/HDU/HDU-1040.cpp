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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
		// 动态数组创建
        int *num;
        num = new int[n];
		// 数据读取
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }
		// 排序
        sort(num, num + n);
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                cout << " ";
            }
            cout << num[i];
            if (i == n - 1) {
                cout << endl;
            }
        }
    }
    return 0;
}
