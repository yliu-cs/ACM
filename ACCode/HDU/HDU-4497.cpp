#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
#define maxn 100000

int d[maxn][2],e[maxn][2],cntn,cntm;

// 唯一分解定理
void Devide(int n,int m) {
    cntn = cntm = 0;
    for (int i = 2;i <= sqrt(n);++i) {
        if (n % i == 0) {
            int num = 0;
            while (n % i == 0) {
                num++;
                n /= i;
            }
            d[++cntn][0] = i;
            d[cntn][1] = num;
        }
    }
    for (int i = 2;i <= sqrt(m);++i) {
        if (m % i == 0) {
            int num = 0;
            while (m % i == 0) {
                num++;
                m /= i;
            }
            e[++cntm][0] = i;
            e[cntm][1] = num;
        }
    }
    if (n > 1) {
        d[++cntn][0] = n;
        d[cntn][1] = 1;
    }
    if (m > 1) {
        e[++cntm][0] = m;
        e[cntm][1] = 1;
    }
}

ll Solve(int n,int m) {
    if (m % n != 0) {
        return 0;
    }
    Devide(n, m);
    ll ans = 1,v;
    for (int i = 1;i <= cntm;++i) {
        int flag = 0;
        for (int j = 1;j <= cntn;++j) {
            if (e[i][0] == d[j][0]) {
                flag = 1;
                v = j;
                break;
            }
        }
        if (!flag) {
            ans = ans * 6 * e[i][1];
        }
        else {
            ll t = e[i][1] - d[v][1];
            if (t == 0) {
                continue;
            }
            ans = ans * 6 * t;
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int G,L;
        cin >> G >> L;
        cout << Solve(G, L) << endl;
    }
    return 0;
}
