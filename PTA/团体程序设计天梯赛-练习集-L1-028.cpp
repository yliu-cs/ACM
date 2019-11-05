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
#include <functional>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 50000;
const double eps = 1e-5;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;

bool IsPrime[maxn];

void Prime() {
    mem(IsPrime, 1);
    for (ll i = 2; i < maxn; ++i) {
        if (IsPrime[i]) {
            for (ll j = i * i; j < maxn; j += i) {
                IsPrime[j] = 0;
            }
        }
    }
    IsPrime[1] = 0;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Prime();
    int n;
    cin >> n;
    while (n--) {
        ll a;
        cin >> a;
        if (a < maxn) {
            if (IsPrime[a]) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
        else {
            bool flag = 1;
            for (int i = 2; i <= sqrt(a); ++i) {
                if (IsPrime[i]) {
                    if (a % i == 0) {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
