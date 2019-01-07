#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <set>
#include <map>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4+5;
const double eps = 1e-5;
const double e = 2.718281828459;

struct information {
    int id;
    int num;
    double money;
    information() {
        num = 0;
        money = 0;
    }
}ac[maxn];

bool cmp(information a, information b) {
    if (a.money == b.money) {
        if (a.num == b.num) {
            return a.id < b.id;
        }
        else {
            return a.num > b.num;
        }
    }
    else {
        return a.money > b.money;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        ac[i].id = i;
        int k;
        cin >> k;
        while (k--) {
            int N, P;
            cin >> N >> P;
            ac[N].num++;
            ac[N].money += P;
            ac[i].money -= P;
        }
    }
    sort(ac + 1, ac + n + 1, cmp);
    for (int i = 1; i <= n; ++i) {
        cout << ac[i].id << " ";
        cout << setiosflags(ios::fixed) << setprecision(2) << ac[i].money / 100.0 << endl;
    }
    return 0;
}
