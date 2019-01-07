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
    int *num;
    num = new int[n];
    stack<int> num1;
    stack<int> num2;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        if (i == 0) {
            num1.push(num[i]);
        }
        else {
            if (num1.empty()) {
                num1.push(num[i]);
            }
            else if (num[i] > num1.top()) {
                num1.push(num[i]);
            }
            else {
                if (num1.size() > num2.size()) {
                    while (!num2.empty()) {
                        num2.pop();
                    }
                    while (!num1.empty()) {
                        num2.push(num1.top());
                        num1.pop();
                    }
                }
                else {
                    while (!num1.empty()) {
                        num1.pop();
                    }
                }
                num1.push(num[i]);
            }
        }
    }
    if (num1.size() > num2.size()) {
        while (!num2.empty()) {
            num2.pop();
        }
        while (!num1.empty()) {
            num2.push(num1.top());
            num1.pop();
        }
    }
    cout << num2.size();
    return 0;
}
