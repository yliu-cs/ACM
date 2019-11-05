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
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6+5;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
 
int n;
int r, c;
int p[maxn];
int magic[maxn];
 
bool judge(int x) {
    int i = c - 1;
    int cnt = 0;
    while (i < n) {
        if (magic[i] <= x) {
            cnt++;
            i += c;
        }
        else {
            i++;
        }
    }
    if (cnt >= r) {
        return 1;
    }
    else {
        return 0;
    }
}
 
int main() {
    //fropen("in.txt", "r", stdin);
    cin >> n >> r >> c;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    sort(p, p + n);
    for (int i = c - 1; i < n; ++i) {
        magic[i] = p[i] - p[i - c  + 1];
    }
    int _left = 0, _right = 1e10+5;
    while (_left < _right) {
        int mid = (_left + _right) >> 1;
        if (judge(mid)) {
            _right = mid;
        }
        else {
            _left = mid + 1;
        }
    }
    cout << _left;
    return 0;
}
