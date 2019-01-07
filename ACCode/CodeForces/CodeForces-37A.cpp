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

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 1010;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Judge[maxn];
    mem(Judge, 0);
    int n;
    cin >> n;
    int *num;
    num = new int[n];
    cin >> num[0];
    Judge[num[0]]++;
    for (int i = 1; i < n; ++i) {
        cin >> num[i];
        int flag = 1;
        for (int j = 0; j < i; ++j) {
            if (num[i] == num[j]) {
                Judge[num[j]]++;
                flag = 0;
                break;
            }
        }
        if (flag) {
            Judge[num[i]]++;
        }
    }
    int max = 0, sum = 0;
    for (int i = 0; i < maxn; ++i) {
        if (Judge[i] != 0) {
            sum++;
        }
        if (Judge[i] > max) {
            max = Judge[i];
        }
    }
    cout << max << " " << sum;
    return 0;
}
