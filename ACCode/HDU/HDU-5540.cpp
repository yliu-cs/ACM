#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x) {
    Finish_read = 0;
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') {
            f = -1;
        }
        if (ch == EOF) {
            return;
        }
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
    Finish_read = 1;
};

// 模拟即可
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    read(t);
    for (int Case = 1; Case <= t; ++Case) {
        int x[4], y[4];
        for (int i = 0; i < 4; ++i) {
            read(x[i]);
        }
        for (int j = 0; j < 4; ++j) {
            read(y[j]);
        }
        bool flag = 0;
        if (x[0] == y[0] && x[1] == y[1] && x[2] == y[2] && x[3] == y[3]) {
            flag = 1;
        }
        else if (x[2] == y[0] && x[0] == y[1] && x[3] == y[2] && x[1] == y[3]) {
            flag = 1;
        }
        else if (x[3] == y[0] && x[2] == y[1] && x[1] == y[2] && x[0] == y[3]) {
            flag = 1;
        }
        else if (x[1] == y[0] && x[3] == y[1] && x[0] == y[2] && x[2] == y[3]) {
            flag = 1;
        }
        printf("Case #%d: ", Case);
        if (!flag) {
            printf("IM");
        }
        printf("POSSIBLE\n");
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
