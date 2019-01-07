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
#define pb push_back
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;

char maze[11][11];

// 模拟
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int temp = 'a';
    for (int size = 3; size <= 10; ++size) {
        mem(maze, ' ');
        for (int i = 1; i <= size; ++i) {
            maze[i][1] = (char)temp++;
            if (temp == 'z' + 1) {
                temp = 'a';
            }
        }
        for (int i = size - 1, j = 2; i > 0 && j <= size; --i, ++j) {
            maze[i][j] = (char)temp++;
            if (temp == 'z' + 1) {
                temp = 'a';
            }
        }
        for (int i = 2; i <= size; ++i) {
            maze[i][size] = (char)temp++;
            if (temp == 'z' + 1) {
                temp = 'a';
            }
        }
        for (int i = 1; i <= size; ++i) {
            for (int j = 1; j <= size; ++j) {
                cout << maze[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
