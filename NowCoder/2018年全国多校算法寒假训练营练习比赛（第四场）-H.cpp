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
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e+5;
const double eps = 1e-5;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;
 
int num[8] = {1, 2, 3, 4, 5, 6, 7, 8};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    do {
        cout << num[0] << " " << num[1] << " " << num[2] << " " << num[3] << " " << num[4] << " " << num[5] << " " << num[6] << " " << num[7] << endl;
    } while(next_permutation(num, num + 8));
    return 0;
}
