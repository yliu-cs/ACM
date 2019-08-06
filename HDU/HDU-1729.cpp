#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

/* 
 * 对于这道题目设盒子容量为s
 * 盒子里有c块石头
 * 求得最大值p使得p*p+p<s
 * p点则为必败点
 * 若c=p则当前状态必败
 * 此点没有后继状态
 * 所以SG值为0
 * 若c>p则当前状态必胜，此点SG值为s-c
 */
// blog:http://henuly.top/?p=484

int cnt;
int n;
int s, c;
int ans;

int sg(int s, int c) {
    int t = sqrt((double)s);
    while (t * t + t >= s) {
        --t;
    }
    if (c > t) {
        return s - c;
    }
    else if (c == t) {
        return 0;
    }
    else {
        return sg(t, c);
    }
}

int main() {
    //fre();
    cnt = 1;
    while (~scanf("%d", &n), n) {
        ans = 0;
        while (n--) {
            scanf("%d%d", &s, &c);
            ans ^= sg(s, c);
        }
        printf("Case %d:\n", cnt++);
        if (ans) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}
