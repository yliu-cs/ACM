#pragma comment(linker, "/STACK:102400000,102400000")
//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
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
const int maxn = 1e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

struct clover {
	int S, E, id;
	clover(int _S = 0, int _E = 0, int _id = 0): S(_S), E(_E), id(_id) {}
};

int n;
int cnt[maxn];
int c[maxn];

bool cmp(clover a, clover b) {
	if (a.E == b.E) {
		return a.S < b.S;
	}
	return a.E > b.E;
}

void update(int x) {
	while (x < maxn) {
		c[x]++;
		x += lowbit(x);
	}
}

int getSum(int x) {
	int ans = 0;
	while (x > 0) {
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
	int n;
	while (~scanf("%d", &n) && n) {
		mem(c, 0);
		mem(cnt, 0);
		vector<clover> cow;
		for (int i = 0, S, E; i < n; ++i) {
			read(S); read(E);
			clover add;
			add.S = S + 1;
			add.E = E + 1;
			add.id = i;
			cow.pb(add);
		}
		sort(cow.begin(), cow.end(), cmp);
		vector<int> ans(n);
		for (int i = 0; i < n; ++i) {
			int temp = i;
			for (int j = i - 1; j >= 0; --j) {
				if (cow[j].S == cow[i].S) {
					if (cow[j].E == cow[i].E) {
						temp = j;
						continue;
					}
				}
				break;
			}
			if (temp != i) {
				ans[cow[i].id] = ans[cow[temp].id];
			}
			else {
				ans[cow[i].id] = getSum(cow[i].S);
			}
			update(cow[temp].S);
		}
		for (int i = 0; i < n; ++i) {
			printf("%d", ans[i]);
			if (i != n - 1) {
				printf(" ");
			}
			else {
				printf("\n");
			}
		}
	}
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
