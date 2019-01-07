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
const int maxn = 2e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

int t;
int n;
int q;
int x, y, z;
int lazy[maxn << 2];
int Add[maxn << 2];

// 向上更新
void PushUp(int rt) {
    lazy[rt] = lazy[rt << 1] + lazy[rt << 1 | 1];
}

// 建树
void Build(int l, int r, int rt) {
    Add[rt] = 0;
    if (l == r) {
        lazy[rt] = 1;
        return;
    }
    int m = (l + r) >> 1;
    Build(l, m, rt << 1);
    Build(m + 1, r, rt << 1 | 1);
    PushUp(rt);
}

// 下推标记
void PushDown(int rt, int ln, int rn) {
    if (Add[rt]) {
        Add[rt << 1] = Add[rt << 1 | 1] = Add[rt];
        lazy[rt << 1] = Add[rt] * ln;
        lazy[rt << 1 | 1] = Add[rt] * rn;
        Add[rt] = 0;
    }
}

// 更新
void Update(int L, int R, int val, int l, int r, int rt) {
    if (L <= l && R >= r) {
        lazy[rt] = val * (r - l + 1);
        Add[rt] = val;
        return;
    }
    int m = (l + r) >> 1;
    PushDown(rt, m - l + 1, r - m);
    if (L <= m) {
        Update(L, R, val, l, m, rt << 1);
    }
    if (R > m) {
        Update(L, R, val, m + 1, r, rt << 1 | 1);
    }
    PushUp(rt);
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    read(t);
    for (int Case = 1; Case <= t; ++Case) {
        read(n);
        read(q);
        Build(1, n, 1);
        while (q--) {
            read(x); read(y); read(z);
            Update(x, y, z, 1, n, 1);
        }
        printf("Case %d: The total value of the hook is %d.\n", Case, lazy[1]);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
//    fclose(stdout);
//    system("gedit out.txt");
#endif
    return 0;
}
