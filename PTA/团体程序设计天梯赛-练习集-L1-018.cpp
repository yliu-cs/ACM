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
    cin >> str;
    int h = (str[0] - '0') * 10 + (str[1] - '0');
    int m = (str[3] - '0') * 10 + (str[4] - '0');
    if (h < 12 || (h == 12 && m == 0)) {
        cout << "Only " << str << ".  Too early to Dang.";
    }
    else {
        h -= 12;
        if (m) {
            h++;
            while (h--) {
                cout << "Dang";
            }
        }
        else {
            while (h--) {
                cout << "Dang";
            }
        }
    }
    return 0;
}

