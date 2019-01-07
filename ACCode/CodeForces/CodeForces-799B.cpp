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
const int maxn = 200010;
const double eps = 1e-5;
const double e = 2.718281828459;

int n, m;
int money[maxn];
int ans[maxn];
int cnt;
set<int> find_color[4];
int judge_color;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    mem(ans, -1);
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> money[i];
	}
	int color_num;
    for (int i = 0; i < n; ++i) {
    	cin >> color_num;
    	find_color[color_num].insert(money[i]);
	}
    for (int i = 0; i < n; ++i) {
    	cin >> color_num;
    	find_color[color_num].insert(money[i]);
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> judge_color;
		if (!find_color[judge_color].size()) {
			ans[cnt++] = -1;
		}
		else {
			set<int>::iterator it;
			it = find_color[judge_color].begin();
			int temp = *it;
			ans[cnt++] = temp;
			for (int j = 1; j <= 3; ++j) {
				it = find_color[j].find(temp);
				if (it != find_color[j].end()) {
					find_color[j].erase(it);
				}
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		cout << ans[i] << " ";
	}
    return 0;
}