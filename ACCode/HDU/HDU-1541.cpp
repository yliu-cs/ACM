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
const int maxn = 3e4+2e3+1;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

int n;
// cnt[i]是等级为i的星星数量
int cnt[maxn];
// c[i]是当前i星星的等级
int c[maxn];

// 更新树状数组
void update(int x) {
    while (x < maxn) {
        c[x]++;
        x += lowbit(x);
    }
}

//　获取x星等级
int getLevel(int x) {
    int level = 0;
    while (x > 0) {
        level += c[x];
        x -= lowbit(x);
    }
    return level;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // 多组数据!
    while (scanf("%d", &n) != EOF) {
        mem(cnt, 0);
        mem(c, 0);
        for (int i = 0, x, y; i < n; ++i) {
            // 题目按照升序给出，所以y没用
            read(x); read(y);
            // 树状数组下表从0开始，但x取值可以为0并且若x为0在getLevel函数中会产生死循环，所以x++
            x++;
            cnt[getLevel(x)]++;
            update(x);
        }
        for (int i = 0; i < n; ++i) {
            printf("%d\n", cnt[i]);
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
