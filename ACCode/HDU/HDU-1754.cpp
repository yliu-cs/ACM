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

int n, m;
int Max[maxn << 4];
char order;
int a, b;

// 向上更新
void PushUp(int rt) {
    Max[rt] = Max[rt << 1] > Max[rt << 1 | 1] ? Max[rt << 1] : Max[rt << 1 | 1];
}

// 建树
void Build(int l, int r, int rt) {
    if (l == r) {
        read(Max[rt]);
        return;
    }
    int m = (l + r) >> 1;
    Build(l, m, rt << 1);
    Build(m + 1, r, rt << 1 | 1);
    PushUp(rt);
}

// 更新
void Update(int pos, int val, int l, int r, int rt) {
    if (l == r) {
        Max[rt] = val;
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m) {
        Update(pos, val, l, m, rt << 1);
    }
    else {
        Update(pos, val, m + 1, r, rt << 1 | 1);
    }
    PushUp(rt);
}

// 询问查询
int Query(int L, int R, int l, int r, int rt) {
    if (L <= l && R >= r) {
        return Max[rt];
    }
    int m = (l + r) >> 1;
    int ans = -INF;
    if (L <= m) {
        int temp = Query(L, R, l, m, rt << 1);
        ans = ans > temp ? ans : temp;
    }
    if (R > m) {
        int temp = Query(L, R, m + 1, r, rt << 1 | 1);
        ans = ans > temp ? ans : temp;
    }
    return ans;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d%d", &n, &m)) {
        mem(Max, 0);
        Build(1, n, 1);
        while (m--) {
            scanf("%c", &order);
            read(a); read(b);
            if (order == 'U') {
                Update(a, b, 1, n, 1);
            }
            else if (order == 'Q') {
                printf("%d\n", Query(a, b, 1, n, 1));
            }
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
//    fclose(stdout);
//    system("gedit out.txt");
#endif
    return 0;
}
