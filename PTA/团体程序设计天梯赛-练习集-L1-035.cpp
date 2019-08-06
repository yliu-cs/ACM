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
const int maxn = 100;
const double eps = 1e-5;
const double e = 2.718281828459;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    string A, B;
    int cnt = 0;
    while (1) {
        cin >> str;
        int len = str.length();
        if (len == 1 && str[0] == '.') {
            break;
        }
        cnt++;
        if (cnt == 2) {
            A = str;
        }
        else if (cnt == 14) {
            B = str;
        }
    }
    if (cnt >= 14) {
        cout << A << " and " << B << " are inviting you to dinner...";
    }
    else if (cnt >= 2) {
        cout << A << " is the only one for you...";
    }
    else {
        cout << "Momo... No one is for you ...";
    }
    return 0;
}
