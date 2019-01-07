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
#include <cstdlib>
#include <sstream>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;

char maze[500][500];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    mem(maze, ' ');
    int n;
    char logo;
    cin >> n >> logo;
    int a, b, r;
    for (int i = 1; i <= 23; ++i) {
        a = 2 * i * i - 1;
        if (a > n) {
            break;
        }
        b = a;
        r = i;
    }
    int last = n - b;
    int emm = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = emm; j < r * 2 - 1 - emm; ++j) {
            maze[i][j] = logo;
        }
        emm++;
    }
    emm = 0;
    for (int i = 2 * r - 2; i > r - 1; --i) {
        for (int j = emm; j < r * 2 - 1 - emm; ++j) {
            maze[i][j] = logo;
        }
        emm++;
    }
    for (int i = 0; i < r * 2 - 1; ++i) {
        for (int j = 0; j < r * 2 - 1; ++j) {
            cout << maze[i][j];
            bool flag = 1;
            if (maze[i][j] == logo && maze[i][j + 1] != logo) {
                for (int k = j + 1; k < r * 2 - 1; ++k) {
                    if (maze[i][k] == logo) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
        }
        cout << endl;
    }
    cout << last;
    return 0;
}
