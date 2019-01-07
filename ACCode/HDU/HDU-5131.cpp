#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 2e2+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

struct info {
    string s;
    int k;
    int index;
}per[maxn];

// 排序规则
bool cmp(info a, info b) {
    if (a.k == b.k) {
        return a.s < b.s;
    }
    return a.k > b.k;
}

int main() {
    //fre();
    int n;
    while (cin >> n, n) {
        for (int i = 1; i <= n; ++i) {
            cin >> per[i].s >> per[i].k;
        }
		// 结构体排序
        sort(per + 1, per + n + 1, cmp);
        int keep = 0, temp;
        for (int i = 1; i <= n; ++i) {
            cout << per[i].s << " " << per[i].k << endl;
            if (i == 1) {
                per[i].index = keep;
                temp = per[i].k;
            }
            else {
                if (per[i].k != temp) {
                    keep = i - 1;
                    per[i].index = keep;
                    temp = per[i].k;
                }
                else {
                    per[i].index = keep;
                }
            }
        }
        int m;
        cin >> m;
        while (m--) {
            string str;
            cin >> str;
            for (int i = 1; i <= n; ++i) {
                if (per[i].s == str) {
                    cout << per[i].index + 1;
                    int mino = i - per[i].index;
                    if (mino != 1) {
                        cout << " " << mino << endl;
                    }
                    else {
                        cout << endl;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}
