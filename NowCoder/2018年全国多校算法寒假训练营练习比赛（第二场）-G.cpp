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
const int maxn = 1e6 + 5;
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
 
bool IsLike[maxn];
int UnlikeNum[maxn];
 
bool judge(int x) {
    while (x) {
        if (x % 10 == 4 || x % 100 == 38) {
            return 1;
        }
        x /= 10;
    }
    return 0;
}
 
void init() {
    mem(IsLike, 0);
    mem(UnlikeNum, 0);
    for (int i = 1; i < maxn; ++i) {
        if (judge(i)) {
            IsLike[i] = 1;
        }
        UnlikeNum[i] = UnlikeNum[i - 1] + IsLike[i];
    }
}
 
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    int n, m;
    while (~scanf("%d %d", &n, &m) && (n + m)) {
        printf("%d\n", UnlikeNum[m] - UnlikeNum[n - 1]);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
