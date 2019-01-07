#pragma comment(linker, "/STACK:102400000,102400000")
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
const int maxn = 37;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
 
struct Group {
    int p, a, c, m, g;
    Group(int _p = 0, int _a = 0, int _c = 0, int _m = 0, int _g = 0): p(_p), a(_a), c(_c), m(_m), g(_g) {}
};
 
int n;
int P, A, C, M;
vector<Group> groups(1);
short dp[maxn][maxn][maxn][maxn];
bool path[maxn][maxn][maxn][maxn][maxn];
vector<int> ans;
 
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n);
    for (int i = 0, p, a, c, m, g; i < n; ++i) {
        read(p); read(a); read(c); read(m); read(g);
        groups.pb(Group {p, a, c, m, g});
    }
    read(P); read(A); read(C); read(M);
    mem(dp, 0);
    mem(path, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = P; j >= groups[i].p; --j) {
                for (int k = A; k >= groups[i].a; --k) {
                        for (int l = C; l >= groups[i].c; --l) {
                                for (int o = M; o >= groups[i].m; --o) {
                                        if (dp[j - groups[i].p][k - groups[i].a][l - groups[i].c][o - groups[i].m] + groups[i].g > dp[j][k][l][o]) {
                                            dp[j][k][l][o] = dp[j - groups[i].p][k - groups[i].a][l - groups[i].c][o - groups[i].m] + groups[i].g;
                                            path[i][j][k][l][o] = 1;
                                        }
                                }
                        }
                }
        }
    }
    for (int i = n, j = P, k = A, l = C, o = M; i >= 1 && j >= 0 && k >= 0 && l >= 0 && o >= 0; --i) {
        if (path[i][j][k][l][o]) {
            ans.pb(i - 1);
            j -= groups[i].p;
            k -= groups[i].a;
            l -= groups[i].c;
            o -= groups[i].m;
        }
    }
    printf("%d\n", int(ans.size()));
    reverse(ans.begin(), ans.end());
    for (auto it : ans) {
        printf("%d ", it);
    }
    printf("\n");
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
