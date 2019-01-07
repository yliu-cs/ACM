#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
const double eps = 1e-5;
const double e = 2.718281828459;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<char> que;
    string str;
    getline(cin, str);
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ',') {
            while (!que.empty()) {
                que.pop();
            }
        }
        if (str[i] != '(' && str[i] != ')' && str[i] != ',') {
            que.push(str[i]);
        }
    }
    while (!que.empty()) {
        cout << que.front();
        que.pop();
    }
    return 0;
}
