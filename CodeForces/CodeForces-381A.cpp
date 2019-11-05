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
    int n;
    cin >> n;
    int *num;
    num = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    int Sereja = 0, Dima = 0, leftflag = 0, rightflag = n - 1;
    int who = 0;
    while (leftflag <= rightflag) {
        if (num[leftflag] > num[rightflag]) {
            if (who % 2 == 0) {
                Sereja += num[leftflag++];
            }
            else {
                Dima += num[leftflag++];
            }
        }
        else {
            if (who % 2 == 0) {
                Sereja += num[rightflag--];
            }
            else {
                Dima += num[rightflag--];
            }
        }
        who++;
    }
    cout << Sereja << " " << Dima;
    return 0;
}
