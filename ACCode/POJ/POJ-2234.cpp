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
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 30;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

int m;
int input;
int temp;

int main(){
    //fre;
    while (~scanf("%d", &m)) {
        temp = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d", &input);
            temp ^= input;
        }
        if (temp == 0) {
            printf("No\n");
        }
        else {
            printf("Yes\n");
        }
    }
    return 0;
}
