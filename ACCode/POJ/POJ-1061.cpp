#pragma comment(linker, "/STACK:102400000,102400000")
//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
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
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;};

ll ExtendGcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = ExtendGcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - a / b * y;
    return d;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
	ll X, Y, M, N, L;
	read(X); read(Y); read(M); read(N); read(L);
	ll a, b, x, y, c;
	a = M - N;
	b = L;
	c = Y - X;
	if (a < 0) {
		a = -a;
		c = -c;
	}
	ll gcd = ExtendGcd(a, b, x, y);
	if (c % gcd != 0) {
		printf("Impossible\n");
	}
	else {
		x = x * c / gcd;
		ll t = b * gcd;
		if (x >= 0) {
			x %= t;
		}
		else {
			x = x % t + t;
		}
		printf("%lld\n", x);
	}
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
