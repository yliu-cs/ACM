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
const int maxn = 1e4 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x) {
    Finish_read = 1;
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

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    read(t);
    for (int Case = 1, n; Case <= t; ++Case) {
        read(n);
        vector<PII> triangles;
        for (int i = 0, x, y; i < 3 * n; ++i) {
            read(x); read(y);
            triangles.pb(mp(x, i + 1));
        }
		// 由于任意三点不共线，所以排序后相邻三点组三角形即可
        sort(triangles.begin(), triangles.end(), [&] (const PII &a, const PII &b) {
            return a.first < b.first;
        });
        while (n--) {
            for (int i = 0; i < 3; ++i) {
                printf("%d ", triangles[i].second);
            }
            triangles.erase(triangles.begin(), triangles.begin() + 3);
            printf("\n");
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
