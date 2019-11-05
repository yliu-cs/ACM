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
const int maxn = 1e5+5;
const double eps = 1e-5;
const double e = 2.718281828459;

int ans = INF;
int temp_x, temp_y;
char input_maze[5][5];
bool suc_flag = 0;
bool maze[5][5];
int line[20][2];

bool suc_judge() {
    for (int i = 1; i < 5; ++i) {
    	for (int j = 1; j < 5; ++j) {
    		if (!maze[i][j]) {
    			return 0;
			}
		}
	}
	return 1;
}

void change(int x, int y) {
	for (int i = 1; i < 5; ++i) {
		maze[x][i] = !maze[x][i];
	}
	for (int i = 1; i < 5; ++i) {
		if (i == x) {
			continue;
		}
		maze[i][y] = !maze[i][y];
	}
}

void print_map() {
    for (int i = 1; i < 5; ++i) {
    	for (int j = 1; j < 5; ++j) {
    		cout << maze[i][j];
		}
		cout << endl;
	}
}

void dfs(int x, int y, int step, bool flag) {
	if (flag) {
		line[step][0] = temp_x;
		line[step][1] = temp_y;
	}
	temp_x = x, temp_y = y;
	if (suc_judge()) {
		if (step < ans) {
			ans = step;
			suc_flag = 1;
		}
		return;
	}
	if (x > 4 || y > 4 || suc_flag) {
		return;
	}
	change(x, y);
	if (y == 4) {
		dfs(x + 1, 1, step + 1, 1);
		if (suc_flag) {
			return;
		}
		change(x, y);
		dfs(x + 1, 1, step, 0);
	}
	else {
		dfs(x, y + 1, step + 1, 1);
		if (suc_flag) {
			return;
		}
		change(x, y);
		dfs(x, y + 1, step, 0);
	}
	if (suc_flag) {
		return;
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    mem(line, -1);
    for (int i = 1; i < 5; ++i) {
    	for (int j = 1; j < 5; ++j) {
    		cin >> input_maze[i][j];
    		maze[i][j] = input_maze[i][j] == '-' ? 1 : 0;
		}
	}
	dfs(1, 1, 0, 0);
	cout << ans << endl;
	for (int i = 1; i <= ans; ++i) {
		cout << line[i][0] << " " << line[i][1] << endl;
	}
    return 0;
}
