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
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int late_h = 0, late_m = 0;
        late_h += n / 60;
        late_m += n % 60;
        cout << 12 + late_h << ":";
        if (late_m < 10) {
            cout << 0 << late_m << endl;
        }
        else {
            cout << late_m << endl;
        }
    }
    return 0;
}
