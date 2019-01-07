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
const int maxn = 100;
const double eps = 1e-5;
const double e = 2.718281828459;

int tall, real_height;

void Judge() {
    double height = (tall - 100) * 1.8;
    if (abs((double)real_height - height) < height * 0.1) {
        cout << "You are wan mei!" << endl;
    }
    else {
        if (real_height > height) {
            cout << "You are tai pang le!" << endl;
        }
        else {
            cout << "You are tai shou le!" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        cin >> tall >> real_height;
        Judge();
    }
    return 0;
}
