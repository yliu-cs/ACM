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

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;

int main() {
    int n;
    cin >> n;
    cin.get();
    for (int i = 0;i < n;++i) {
        stack<char> s;
        bool flag = 1;
        string ch;
        getline(cin,ch);
        //cout << ch << endl;
        int len = ch.length();
        if (len == 0) {
            cout << "Yes" << endl;
            continue;
        }
        for (int j = 0;j < len;++j) {
            if (ch[j] == '(' || ch[j] == '[') {
                s.push(ch[j]);
            }
            else if (ch[j] == ')' || ch[j] == ']') {
                if (s.size() == 0) {
                    flag = 0;
                    break;
                }
                if (ch[j] == ')' && s.top() == '(') {
                    s.pop();
                }
                else if (ch[j] == ']' && s.top() == '[' ) {
                    s.pop();
                }
            }
        }
        if (flag) {
            if (s.size() == 0) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}