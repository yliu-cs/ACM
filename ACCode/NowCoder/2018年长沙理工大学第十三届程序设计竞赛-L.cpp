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
#include <map>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 52;
const double eps = 1e-5;
const double e = 2.718281828459;
 
int t;
int a, b, n;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b >> n;
        int a_sum = 0, b_sum = 0;
        bool flag = 0;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            if (flag) {
                continue;
            }
            if (num == 1) {
                if (a_sum < a) {
                    a_sum++;
                }
                else {
                    if (b_sum < b) {
                        b_sum++;
                    }
                    else {
                        cout << "No" << endl;
                        flag = 1;
                    }
                }
            }
            else {
                if (b_sum < b) {
                    if (num / 2 <= b - b_sum) {
                        b_sum += num / 2;
                        num %= 2;
                        if (num != 0) {
                            if (a_sum < a) {
                                a_sum++;
                            }
                            else {
                                cout << "No" << endl;
                                flag = 1;
                            }
                        }
                    }
                    else {
                        num -= (b - b_sum) * 2;
                        b_sum = b;
                        if (a_sum + num <= a) {
                            a_sum += num;
                        }
                        else {
                            cout << "No" << endl;
                            flag = 1;
                        }
                    }
                }
                else {
                    if (a_sum + num <= a) {
                        a_sum += num;
                    }
                    else {
                        cout << "No" << endl;
                        flag = 1;
                    }
                }
            }
        }
        if (!flag) {
            cout << "Yes" << endl;
        }
    }
    return 0;
}
