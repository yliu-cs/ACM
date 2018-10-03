#pragma comment(linker, "/STACK:102400000,102400000")
//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
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
const int maxn = 5e5+10;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

struct discrete {
    int val;
    int pos;
    discrete(int _val = 0, int _pos = 0): val(_val), pos(_pos) {}
    bool operator < (const discrete &a) const {
        return val < a.val;
    }
}origin[maxn];

int n;
ll ans;
int v[maxn];
int c[maxn];

void update(int x) {
    while (x < maxn) {
        c[x]++;
        x += lowbit(x);
    }
}

int getSum(int x) {
    int res = 0;
    while (x > 0) {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d", &n) && n) {
        for (int i = 1, x; i <= n; ++i) {
            read(origin[i].val);
            origin[i].pos = i;
        }
        sort(origin + 1, origin + n + 1);
        for (int i = 1; i <= n; ++i) {
            v[origin[i].pos] = i;
        }
        mem(c, 0);
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            update(v[i]);
            ans += i - getSum(v[i]);
        }
        printf("%lld\n", ans);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
