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

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 1e+5;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double ans,a,b,n;
    char c;
    while (1) {
        stack<double> S;
        ans = 0;
        cin >> n;
        c = getchar();
        if (n == 0 && c == '\n') {
            break;
        }
		// 符号入栈
        S.push(n);
        while (cin >> c >> n) {
			// 加减压入栈中
            if (c == '+') {
                S.push(n);
            }
            else if (c == '-') {
                S.push(-n);
            }
			// 乘除计算后压入栈中
            else if (c == '*') {
                n = S.top() * n;
                S.pop();
                S.push(n);
            }
            else if (c == '/') {
                n = S.top() / n;
                S.pop();
                S.push(n);
            }
            if (getchar() == '\n') {
                break;
            }
        }
		// 最后计算加减
        while (!S.empty()) {
            ans += S.top();
            S.pop();
        }
        cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
    }
    return 0;
}
