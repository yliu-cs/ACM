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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r1, c1;
    cin >> r1 >> c1;
    int **num1;
    num1 = new int*[r1];
    for (int i = 0; i < r1; ++i) {
        num1[i] = new int[c1];
    }
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            cin >> num1[i][j];
        }
    }
    int r2, c2;
    cin >> r2 >> c2;
    int **num2;
    num2 = new int*[r2];
    for (int i = 0; i < r2; ++i) {
        num2[i] = new int[c2];
    }
    for (int i = 0; i < r2; ++i) {
        for (int j = 0; j < c2; ++j) {
            cin >> num2[i][j];
        }
    }
    if (c1 != r2) {
        cout << "Error: " << c1 << " != " << r2;
    }
    else {
        int **res;
        res = new int*[r1];
        for (int i = 0; i < r1; ++i) {
            res[i] = new int[c2];
        }
        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c2; ++j) {
                res[i][j] = 0;
            }
        }
        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c2; ++j) {
                for (int k = 0; k < c1; ++k) {
                    res[i][j] += num1[i][k] * num2[k][j];
                }
            }
        }
        cout << r1 << " " << c2 << endl;
        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c2; ++j) {
                cout << res[i][j];
                if (j != c2 - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}
