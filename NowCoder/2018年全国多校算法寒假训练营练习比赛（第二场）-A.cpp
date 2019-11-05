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
const int INF = 0x3f3f3f3f;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int flag;
    while (getline(cin,s)) {
        stack<char> q;
        int len = s.length();
        for (int i = 0;i < len;++i) {
            if (s[i] == 'o' && !q.empty() && q.top() == 'o') {
                q.pop();
                if (!q.empty() && q.top() == 'O') {
                    q.pop();
                }
                else {
                    q.push('O');
                }
            }
            else if (s[i] == 'O' && !q.empty() && q.top() == 'O') {
                q.pop();
            }
            else {
                q.push(s[i]);
            }
        }
        s = "";
        stack<char> l;
        while (!q.empty()) {
            l.push(q.top());
            q.pop();
        }
        while (!l.empty()) {
            cout << l.top();
            l.pop();
        }
        cout << endl;
        s = "";
    }
    return 0;
}
