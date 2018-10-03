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
const int maxn = 4e3 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x) {
    Finish_read = 0;
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') {
            f = -1;
        }
        if (ch == EOF) {
            return;
        }
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
    Finish_read = 1;
};
 
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    read(t);
    for (int Case = 1, n, m; Case <= t; ++Case) {
        read(n); read(m);
        map<int, int> mp;
        for (int i = 0, x; i < n; ++i) {
            read(x);
            mp[x]++;
        }
        vector<PII> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), [&] (const PII &a, const PII &b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second > b.second;
        });
        int ans = -1;
        int amount = 0;
        for (int i = 0; i < int(vec.size()); ++i) {
            if (vec[i].second != vec[i - 1].second) {
                int cnt = i;
                for (int j = i + 1; vec[j].second == vec[j - 1].second && j < int(vec.size()); ++j) {
                    amount += vec[j].second;
                    cnt++;
                }
                int temp = amount - cnt * (vec[i].second - 1);
                if (temp <= m && vec[i].first > ans) {
                    ans = vec[i].first;
                }
                amount += vec[i].second;
            }
        }
        printf("%d\n", ans);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
