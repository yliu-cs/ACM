
/*-----------------------------------------------------------*/
/*                     Blog        :henuly.top               */
/*-----------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
#define XDebug(x) cout<<#x<<"="<<x<<endl;
#define ArrayDebug(x,i) cout<<#x<<"["<<i<<"]="<<x[i]<<endl;
#define print(x) out(x);putchar('\n')
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<ll,ll> PLL;
const int INF = 0x3f3f3f3f;
const int maxn = 7e1 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;
template <class T>
inline bool read(T &ret) {
    char c;
    int sgn;
    if (c = getchar(), c == EOF) {
        return 0;
    }
    while (c != '-' && (c < '0' || c > '9')) {
        c = getchar();
    }
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9') {
        ret = ret * 10 + (c - '0');
    }
    ret *= sgn;
    return 1;
}
template <class T>
inline void out(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        out(x / 10);
    }
    putchar(x % 10 + '0');
}

int n;
int Max;
int sum;
int ans;
int cnt;
int len[maxn];
bool vis[maxn];

void dfs(int target, int value, int pos) {
    if (count(vis, vis + n, 0) == 0) {
        if (!value) {
            ans = target;
            return;
        }
    }
    // 从当前下标开始向后搜索
    for (int i = pos; i < n; ++i) {
        if (!vis[i] && value + len[i] <= target) {
            vis[i] = 1;
            if (value + len[i] == target) {
                // 若已组成目标长度木棒，则从第一根没有匹配的木棒开始搜索
                dfs(target, 0, 0);
                if (ans) {
                    return;
                }
            }
            else {
                dfs(target, value + len[i], i + 1);
                if (ans) {
                    return;
                }
            }
            vis[i] = 0;
            // 这个剪枝判断不加超时，加上0ms（目的是尽可能的在靠近树根处剪枝）
            if (!value) {
                return;
            }
            // 跳过长度相等的木棒
            while (i + 1 < n && len[i + 1] == len[i]) {
                ++i;
            }
        }
    }
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (read(n) && n) {
        sum = 0;
        Max = -1;
        for (int i = 0; i < n; ++i) {
            read(len[i]);
            // 最长木棒
            Max = max(Max, len[i]);
            // 木棒长度之和
            sum += len[i];
        }
        // 将木棒按照降序排列，优先使用长的木棒
        sort(len, len + n, [&] (const int &a, const int &b) {
            return a > b;
        });
        for (int i = Max, cnt = 0; i <= sum; ++i) {
            // 枚举可能的结果
            if (!(sum % i)) {
                ans = 0;
                mem(vis, 0);
                vis[0] = 1;
                // dfs搜索
                dfs(i, len[0] == i ? 0 : len[0], 0);
                // 若搜索成功则跳出
                if (ans) {
                    break;
                }
            }
        }
        print(ans);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
