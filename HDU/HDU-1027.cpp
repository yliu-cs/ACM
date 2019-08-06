//#include<bits/stdc++.h>
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
const int maxn = 1010;
const double eps = 1e-5;
const double e = 2.718281828459;

int n, m;
int num[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    while (cin >> n >> m) {
        for (int i = 0; i < maxn; ++i) {
            num[i] = i + 1;
        }
        cnt = 0;
		// 组合数
           do {
                cnt++;
                if (cnt == m) {
                for (int i = 0; i < n; ++i) {
                    cout << num[i];
                    if (i != n - 1) {
                        cout << " ";
                    }
                }
                cout << endl;
            }
            else if (cnt > m) {
                break;
            }
        } while(next_permutation(num, num + n));
    }
    return 0;
}
