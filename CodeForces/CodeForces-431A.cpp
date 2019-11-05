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
const int maxn = 1010;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a[5], sum = 0;
    for (int i = 1; i <= 4; ++i) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; ++i) {
        int temp = s[i] - '0';
        sum += a[temp];
    }
    cout << sum;
    return 0;
}
