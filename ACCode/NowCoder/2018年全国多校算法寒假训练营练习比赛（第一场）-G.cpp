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
 
char map[3000][3000];
 
void Fractal(int n, int x, int y) {
    if (n == 1) {
        map[x][y] = 'O';
    }
    else {
        int k = pow(3, n - 2);
        Fractal(n - 1, x, y + k);
        Fractal(n - 1, x + k, y + 2 * k);
        Fractal(n - 1, x + k, y);
        Fractal(n - 1, x + 2 * k, y + k);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n++;
        int size = pow(3, n - 1);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                map[i][j] = ' ';
            }
        }
        Fractal(n, 0, 0);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                bool flag = 0;
                cout << map[i][j];
                if (map[i][j] == 'O' && map[i][j + 1] == ' ') {
                    for (int k = j + 1; k < size;++k) {
                        if (map[i][k] == 'O') {
                            flag = 1;
                            break;
                        }
                    }
                    if (!flag) {
                        break;
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}
