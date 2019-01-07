#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 102;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
inline void fre() {freopen("in.txt", "r", stdin);/*freopen("out.txt", "w", stdout);*/}
 
int n, a, b;
bitset<1000005> s1, s2;
  
int main() {
    //fre();
    read(n);
    s1.set(0);
    while (n--) {
        read(a);
        read(b);
        s2.reset();
        for (int i = a; i <= b; ++i) {
            s2 |= s1 << (i * i);
        }
        swap(s1, s2);
    }
    printf("%d\n", (int)s1.count());
    return 0;
}
