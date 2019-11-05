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

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

// 每个节目信息
struct Show {
    int Ti_s;
    int Ti_e;
}q[100];

// 排序规则
bool cmp(Show A,Show B) {
    return A.Ti_e < B.Ti_e;
}

// 信息读取
void GetInformation(int x) {
    for (int i = 0 ; i < x ; ++i) {
        cin >> q[i].Ti_s >> q[i].Ti_e;
    }
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        GetInformation(n);
		// 贪心排序
        sort(q,q + n,cmp);
        int x = q[0].Ti_e;
        int Book = 1;
        for (int i = 0 ; i < n ; ++i) {
            int y = q[i].Ti_s;
            if (y >= x) {
                Book++;
                x = q[i].Ti_e;
            }
        }
        cout << Book << endl;
    }
    return 0;
}

