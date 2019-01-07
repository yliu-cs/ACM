
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
 
bool Judge[10] = {0};
int d[5] = {10,100,1000,10000,100000};
bool IsLike[1010];
int a,b;
 
void Like() {
    mem(IsLike, 0);
    for (int i = 0;i < 1010;++i) {
        if (i % a == 0 || i % b == 0) {
            IsLike[i] = 1;
            continue;
        }
        for (int j = 0;j < 3;++j) {
            int judgeLike = i;
            if (i >= d[j]) {
                judgeLike /= d[j];
            }
            judgeLike %= 10;
            if (Judge[judgeLike] == 1) {
                IsLike[i] = 1;
                break;
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        mem(Judge, 0);
        for (int i = 0;i < 5;++i) {
            int a1 = a,b1 = b;
            if (a >= d[i]) {
                a1 /= d[i];
            }
            if (b > d[i]) {
                b1 /= d[i];
            }
            a1 %= 10;
            b1 %= 10;
            Judge[a1] = 1;
            Judge[b1] = 1;
        }
        Like();
        ll sum = 0;
        for (int i = 1;i <= 1000;++i) {
            if (IsLike[i] == 0) {
                sum++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
