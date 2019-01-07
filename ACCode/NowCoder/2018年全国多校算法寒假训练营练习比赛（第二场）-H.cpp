#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
 
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int INF = 0x3f3f3f3f;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll num[52];
    num[1] = 0;
    num[2] = 1;
    num[3] = 1;
    for (int i = 4;i <= 50;++i) {
        num[i] = num[i - 1] + num[i - 2] + num[i - 3];
    }
    int n;
    while (cin >> n) {
        cout << num[n] << endl;
    }
    return 0;
}
