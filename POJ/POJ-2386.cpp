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

const int maxn = 110;
char field[maxn][maxn];
int N,M,res;

void dfs(int x,int y) {
    field[x][y] = '.';
    for (int dx= -1;dx <= 1;dx++) {
        for (int dy = -1;dy <= 1;dy++) {
            int nx = x + dx;
            int ny = y + dy;
            if (0 < nx && nx <= N && 0 < ny && ny <= M && field[nx][ny] == 'W') {
                dfs(nx,ny);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 1;i <= N;++i) {
        for (int j = 1;j <= M;++j) {
            cin >> field[i][j];
        }
    }
    for (int i = 1;i <= N;++i) {
        for (int j = 1;j <= M;++j) {
            if (field[i][j] == 'W') {
                dfs(i,j);
                res++;
            }
        }
    }
    cout << res;
    return 0;
}
