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
const int maxn = 1e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
 
// 询问结构体
struct query {
    int l, r, id;
    query(int _l = 0, int _r = 0, int _id = 0): l(_l), r(_r), id(_id) {}
};
 
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, q;
    while (~scanf("%d%d", &n, &q)) {
        vector<int> a(n + 1), first(n + 1, -1), last(n + 1);
        // 统计不同数字个数
        int total = 0;
        for (int i = 1; i <= n; ++i) {
            read(a[i]);
            // 覆盖记录数字最后一次出现位置
            last[a[i]] = i;
            // 记录数字第一次出现的位置并将数字个数+1
            if (first[a[i]] == -1) {
                ++total;
                first[a[i]] = i;
            }
        }
        // 读入存储每个询问
        vector<query> Query;
        for (int i = 0, l, r; i < q; ++i) {
            read(l); read(r);
            Query.pb(query {l, r, i});
        }
        // 将询问按照右端点升序排序
        sort(Query.begin(), Query.end(), [&] (const query &a, const query &b) {
            return a.r < b.r;
        });
        vector<int> ans(q), count(n + 1, 0);
        // 从左至右遍历每个位置
        for (int i = 1, k = 0; i <= n; ++i) {
            // 若还有未处理的询问并且正在遍历此询问右端点
            while (k < q && Query[k].r == i) {
                // 先把此询问结果赋值为所有范围内不同数字个数
                ans[Query[k].id] = total;
                //　从此询问左端点开始遍历至最右减去在左端点至右端点不统计的数字个数
                for (int j = Query[k].l; j <= n; j += lowbit(j)) {
                    ans[Query[k].id] -= count[j];
                }
                // 处理询问数+1
                ++k;
            }
            // 若查询处理完毕则跳出
            if (k >= q) {
                break;
            }
            // 若遍历到的位置上的数字为最后一次出现，则把它第一次出现的位置之前count+1
            if (last[a[i]] == i) {
                for (int j = first[a[i]] - 1; j > 0; j -= lowbit(j)) {
                    count[j]++;
                }
            }
        }
        // 输出结果
        for (auto i : ans) {
            printf("%d\n", i);
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
