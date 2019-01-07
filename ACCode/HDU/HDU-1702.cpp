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

// 按照题意使用栈或者队列模拟
int main() {
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        string Rule;
        cin >> Rule;
        if (Rule == "FIFO") {
            queue<int> s1;
            while (N--) {
                string Judge;
                cin >> Judge;
                if (Judge == "IN") {
                    int a;
                    cin >> a;
                    s1.push(a);
                }
                else {
                    if (s1.size() == 0) {
                        cout << "None" << endl;
                    }
                    else {
                        cout << s1.front() << endl;
                        s1.pop();
                    }
                }
            }
        }
        else {
            stack<int> s2;
            while (N--) {
                string Judge;
                cin >> Judge;
                if (Judge == "IN") {
                    int a;
                    cin >> a;
                    s2.push(a);
                }
                else {
                    if (s2.size() == 0) {
                        cout << "None" << endl;
                    }
                    else {
                        cout << s2.top() << endl;
                        s2.pop();
                    }
                }
            }
        }
    }
    return 0;
}
