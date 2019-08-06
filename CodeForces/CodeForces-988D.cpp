#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

int main(){
    //fre();
    set<int> s;
    int n;
    scanf("%d", &n);
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
        s.insert(x[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 31; ++j) {
            // set用find寻找容器内没有的值返回set.end()
            // 位运算计算2的阶乘
            if (s.find(x[i] - (1 << j)) != s.end() && s.find(x[i] + (1 << j)) != s.end()) {
                printf("3\n%d %d %d", x[i] - (1 << j), x[i], x[i] + (1 << j));
                return 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 31; ++j) {
            if (s.find(x[i] - (1 << j)) != s.end()) {
                printf("2\n%d %d", x[i] - (1 << j), x[i]);
                return 0;
            }
        }
    }
    printf("1\n%d", x[0]);
    return 0;
}
