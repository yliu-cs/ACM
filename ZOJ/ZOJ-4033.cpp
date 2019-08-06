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
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

int main() {
    //fre();
    int t;
    cin >> t;
    while (t--) {
        string str, ans;
        ll n, sum;
        cin >> n;
        cin >> str;
        ans.resize(n, ' ');
        sum = n * (n + 1) / 2;
        if (sum % 2) {
            cout << -1 << endl;
            continue;
        }
        else {
            ll num = sum / 2;
            for (int i = n; i >= 1; --i) {
                if (num <= n && ans[num - 1] == ' ') {
                    if (str[num - 1] == '1') {
                        ans[num - 1] = '3';
                    }
                    else {
                        ans[num - 1] = '1';
                    }
                    break;
                }
                num -= i;
                if (str[i - 1] == '1') {
                    ans[i - 1] = '3';
                }
                else {
                    ans[i - 1] = '1';
                }
            }
            for (int i = n; i >= 1; --i) {
                if (ans[i - 1] == ' ') {
                    if (str[i - 1] == '1') {
                        ans[i - 1] = '4';
                    }
                    else {
                        ans[i - 1] = '2';
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}

