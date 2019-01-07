#pragma comment(linker, "/STACK:102400000,102400000")
//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
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
const int maxn = 2e4+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

struct Cow {
    int hear;
    int pos;
    Cow(int _hear = 0, int _pos = 0): hear(_hear), pos(_pos) {}
    bool operator < (const Cow &a) const {
        return hear < a.hear;
    }
};

int n;
ll ans;
int totaldis;
int c[maxn];
int d[maxn];

void update(int x, int val, int *arr) {
    while (x < maxn) {
        arr[x] += val;
        x += lowbit(x);
    }
}

ll getSum(int x, int *arr) {
    ll res = 0;
    while (x > 0) {
        res += arr[x];
        x -= lowbit(x);
    }
    return res;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d", &n)) {
        vector<Cow> cows;
        for (int i = 0, h, p; i < n; ++i) {
            read(h); read(p);
            cows.pb(Cow {h, p});
        }
        sort(cows.begin(), cows.end());
        mem(c, 0);
        mem(d, 0);
        ans = 0;
        totaldis = 0;
        for (int i = 0; i < n; ++i) {
            ll count = getSum(cows[i].pos, c);
            ll dis = getSum(cows[i].pos, d);
            ans += cows[i].hear * (count * cows[i].pos - dis);
            ans += cows[i].hear * ((totaldis - dis - (i - count) * cows[i].pos));
            totaldis += cows[i].pos;
            update(cows[i].pos, 1, c);
            update(cows[i].pos, cows[i].pos, d);
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
