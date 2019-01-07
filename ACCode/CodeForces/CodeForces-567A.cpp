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
    int n;
    cin >> n;
    int *num;
    num = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    for (int i = 0; i < n; ++i) {
        int min = INF, max = -1;
        if (i == 0) {
            min = num[1] - num[0];
        }
        else if (i > 0 && i != n - 1) {
            min = (num[i] - num[i - 1]) < (num[i + 1] - num[i]) ? (num[i] - num[i - 1]) : (num[i + 1] - num[i]);
        }
        else {
            min = num[n - 1] - num[n - 2];
        }
        max = (num[i] - num[0]) > (num[n - 1] - num[i]) ? (num[i] - num[0]) : (num[n - 1] - num[i]);
        cout << min << " " << max << endl;
    }
    return 0;
}
