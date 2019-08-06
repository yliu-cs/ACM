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
bool suc_flag = 0;
char input_maze[5][5];
bool maze[5][5];

bool suc_judge() {
	for (int i = 1; i < 5; ++i) {
		for (int j = 1; j < 5; ++j) {
			if (maze[i][j] != maze[1][1]) {
				return 0;
			}
		}
	}
	return 1;
}

void change(int x, int y) {
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (abs(i) != abs(j) || (i == 0 && j == 0)) {
				int nx = x + i, ny = y + j;
				if (nx >= 0 && nx <= 4 && ny >= 0 && ny <= 4) {
					maze[nx][ny] = !maze[nx][ny];
				}
			}
		}
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

void dfs(int x, int y, int step) {
	if (suc_judge()) {
		if (step < ans) {
			ans = step;
		}
		suc_flag = 1;
		return;
	}
	if (x > 4 || y > 4) {
		return;
	}
	change(x, y);
	if (y == 4) {
		dfs(x + 1, 1, step + 1);
		change(x, y);
		dfs(x + 1, 1, step); 
	}
	else {
		dfs(x, y + 1, step + 1);
		change(x, y);
		dfs(x, y + 1, step);
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	for (int i = 1; i < 5; ++i) {
		for (int j = 1; j < 5; ++j) {
			cin >> input_maze[i][j];
			maze[i][j] = input_maze[i][j] == 'b' ? 1 : 0;
		}
	}
	dfs(1, 1, 0);
	if (suc_flag) {
		cout << ans;
	}
	else {
		cout << "Impossible";
	}
    return 0;
}
