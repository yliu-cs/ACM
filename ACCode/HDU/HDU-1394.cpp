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
const int maxn = 4e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n)) {
        int ans = 0;
        vector<int> a(n);
        for (int i = 0, x; i < n; ++i) {
            read(a[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[j] > a[i]) {
                    ans++;
                }
            }
        }
        int temp = ans;
        for (int i = 0; i < n - 1; ++i) {
			// 逆序数性质
            temp += n - 2 * a[i] - 1;
            ans = temp < ans ? temp : ans;
        }
        printf("%d\n", ans);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
//    fclose(stdout);
//    system("gedit out.txt");
#endif
    return 0;
}
