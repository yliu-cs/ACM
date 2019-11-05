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
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n) {
        if (n < 3) {
            cout << "XiaoNiu" << endl;
        }
        else {
            cout << "XiaoKe" << endl;
        }
    }
    return 0;
}
