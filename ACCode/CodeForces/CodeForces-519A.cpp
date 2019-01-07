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
const int maxn = 1e5+5;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    char maze[8][8];
    int black = 0, white = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> maze[i][j];
            if (maze[i][j] == 'Q' || maze[i][j] == 'q') {
                if (isupper(maze[i][j])) {
                    white += 9;
                }
                else {
                    black += 9;
                }
            }
            else if (maze[i][j] == 'R' || maze[i][j] == 'r') {
                if (isupper(maze[i][j])) {
                    white += 5;
                }
                else {
                    black += 5;
                }
            }
            else if (maze[i][j] == 'B' || maze[i][j] == 'b' || maze[i][j] == 'N' || maze[i][j] == 'n') {
                if (isupper(maze[i][j])) {
                    white += 3;
                }
                else {
                    black += 3;
                }
            }
            else if (maze[i][j] == 'P' || maze[i][j] == 'p') {
                if (isupper(maze[i][j])) {
                    white += 1;
                }
                else {
                    black += 1;
                }
            }
        }
    }
    if (white > black) {
        cout << "White";
    }
    else if (white < black) {
        cout << "Black";
    }
    else {
        cout << "Draw";
    }
    return 0;
}
