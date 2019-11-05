#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int INF = 0x3f3f3f3f;
const int maxn = 3e2+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
 
int n, m1, m2;
int cnt1, cnt2;
bool adj1[maxn][maxn];
bool adj2[maxn][maxn];
int _map[maxn];
 
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d%d%d", &n, &m1, &m2)) {
        mem(adj1, 0);
        mem(adj2, 0);
        cnt1 = 0, cnt2 = 0;
        vector<PII> edge;
        for (int i = 0, a, b; i < m1; ++i) {
            read(a); read(b);
            edge.pb(mp(a, b));
            adj1[a][b] = adj1[b][a] = 1;
        }
        for (int i = 0, a, b; i < m2; ++i) {
            read(a); read(b);
            adj2[a][b] = adj2[b][a] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            _map[i] = i;
        }
        do {
            bool flag1 = 1, flag2 = 1;
            for (auto i : edge) {
                if (!adj1[_map[i.first]][_map[i.second]]) {
                    flag1 = 0;
                }
                if (!adj2[_map[i.first]][_map[i.second]]) {
                    flag2 = 0;
                }
            }
            if (flag1) {
                ++cnt1;
            }
            if (flag2) {
                ++cnt2;
            }
        } while(next_permutation(_map + 1, _map + n + 1));
        printf("%d\n", cnt2 / cnt1);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
