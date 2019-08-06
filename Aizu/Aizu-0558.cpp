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

struct site {
	int a;
	int b;
};

int h, w, n;
int st_x, st_y;
int en_x, en_y;
int d[maxn][maxn];
int ans = 0;
char maze[maxn][maxn];
int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};

void bfs() {
	queue<site> que;
    mem(d, INF);
	site q;
	q.a = st_x, q.b = st_y;
	que.push(q);
	d[st_x][st_y] = 0;
	while (que.size()) {
		site p = que.front();
		que.pop();
		if (p.a == en_x && p.b == en_y) {
			break;
		}
		for (int i = 0; i <= 3; ++i) {
			int nx = p.a + dx[i], ny = p.b + dy[i];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w && maze[nx][ny] != 'X' && d[nx][ny] == INF) {
				site add;
				add.a = nx;
				add.b = ny;
				que.push(add);
				d[nx][ny] = d[p.a][p.b] + 1;
			}
		}
	}
	ans += d[en_x][en_y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> h >> w >> n;
    char end_ch = n + '0';
    for (int i = 0; i < h; ++i) {
    	for (int j = 0; j < w; ++j) {
    		cin >> maze[i][j];
    		if (maze[i][j] == 'S') {
    			st_x = i;
    			st_y = j;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < h; ++j) {
			for (int k = 0; k < w; ++k) {
				if (maze[j][k] == '0' + i) {
					en_x = j;
					en_y = k;
					bfs();
					st_x = j;
					st_y = k;
				}
			}
		}
	}
	cout << ans << endl;
    return 0;
}
