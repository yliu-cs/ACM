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

// 按照题意模拟
int main() {
    int N;
    cin >> N;
    while (N--) {
        int a;
        cin >> a;
        vector<int> s;
        for (int i = 1;i <= a;++i) {
            s.push_back(i);
        }
        while (s.size() > 3) {
			// 这里一定要写s.size()，因为会变
            for (int i = 1;i < s.size();++i) {
                s.erase(s.begin() + i);
            }
            if (s.size() <= 3) {
                break;
            }
            for (int i = 2;i < s.size();i += 2) {
                s.erase(s.begin() + i);
            }
        }
        for (int i = 0;i < s.size();++i) {
            cout << s[i];
            if (i != (s.size() - 1)) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
