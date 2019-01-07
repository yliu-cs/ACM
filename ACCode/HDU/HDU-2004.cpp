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
#define _USE_MATH_DEFINES
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    while (cin >> n) {
        if (n >= 0 && n <= 100) {
            if (n >= 90 && n <= 100) {
                cout << "A" << endl;
            }
            else if (n >= 80 && n <= 89) {
                cout << "B" << endl;
            }
            else if (n >= 70 && n <= 79) {
                cout << "C" << endl;
            }
            else if (n >= 60 && n <= 69) {
                cout << "D" << endl;
            }
            else {
                cout << "E" << endl;
            }
        }
        else {
            cout << "Score is error!" << endl;
        }
    }
    return 0;
}
