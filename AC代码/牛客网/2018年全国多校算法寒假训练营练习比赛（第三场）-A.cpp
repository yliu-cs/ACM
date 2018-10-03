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
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;
 
double Stirling_8(int n) {
    return (log(2 * pi * n) / 2 + n * log(n / e)) / log(8) + 1;
}
 
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        double digit_8 = Stirling_8(n);
        if (n < 2) {
            digit_8 = 1;
        }
        printf("%d\n", (int)digit_8 );
    }
    return 0;
}
