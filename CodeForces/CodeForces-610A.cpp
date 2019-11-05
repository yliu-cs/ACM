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
    int n, sum = 0;
    cin >> n;
    if (n % 2 != 0 || n < 5) {
        cout << sum;
    }
    else {
        int length = n / 2;
        if (length % 2 != 0) {
            cout << length  / 2;
        }
        else {
            cout << length / 2 - 1;
        } 
    }
    return 0;
}
