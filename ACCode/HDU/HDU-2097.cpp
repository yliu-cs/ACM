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

// 进制转换
int ChangeAdd(int n, int system) {
    int sum = 0;
    while (n > 0) {
        sum += n % system;
        n /= system;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n, n) {
        int ten = ChangeAdd(n, 10), twelve = ChangeAdd(n, 12), sixteen = ChangeAdd(n, 16);
        if (ten == twelve && twelve == sixteen && ten == sixteen) {
            cout << n << " is a Sky Number." << endl;
        }
        else {
            cout << n << " is not a Sky Number." << endl;
        }
    }
    return 0;
}
