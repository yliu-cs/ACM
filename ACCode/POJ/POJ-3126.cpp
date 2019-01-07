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
const int maxn = 10000;
const int INF = 1000000000;

bool IsPrime[maxn];
int WorkPrime[maxn];
int A,B;
int da[19] = {-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9},db[4] = {1,10,100,1000};

void _Prime() {
    mem(IsPrime, 1);
    IsPrime[1] = 0;
    for (int i = 2;i < maxn;++i) {
        if (IsPrime[i]) {
            for (int j = i * i;j < maxn;j += i) {
                IsPrime[j] = 0;
            }
        }
    }
}

int bfs() {
    queue<int> que;
    for (int i = 0;i < maxn;++i) {
        WorkPrime[i] = INF;
    }
    que.push(A);
    WorkPrime[A] = 0;
    while (que.size()) {
        int p = que.front();
        que.pop();
        if (p == B) {
            break;
        }
        for (int i = 0;i < 19;++i) {
            for (int j = 0;j < 4;++j) {
                int Num1;
                if (j < 3) {
                    Num1 = p % db[j + 1] / db[j];
                }
                else {
                    Num1 = p / db[j];
                }
                Num1 += da[i];
                if (Num1 >= 0 && Num1 <= 9) {
                    int d = p + da[i] * db[j];
                    if (d >= 1000 && IsPrime[d] == 1 && WorkPrime[d] == INF) {
                        que.push(d);
                        WorkPrime[d] = WorkPrime[p] + 1;
                    }
                }
            }
        }
    }
    return WorkPrime[B];
}

int main() {
    ios::sync_with_stdio(0);
    _Prime();
    int T;
    cin >> T;
    while (T--) {
        cin >> A >> B;
        int res = bfs();
        cout << res << endl;
    }
    return 0;
}
