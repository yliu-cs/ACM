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

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 1e+5;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    string ans;
    cin >> T;
    while (T--) {
        vector<string> vec;
        vector<string>::iterator it;
        int n;
        cin >> n;
        int flag = 1;
        ans.clear();
        while (n--) {
            string str;
            cin >> str;
            vec.push_back(str);
			// 一定是最长串包含其它字符串
            if (ans.length() < str.length()) {
                ans = str;
            }
        }
		// 子串寻找
        for (it = vec.begin();it != vec.end();it++) {
            if (ans.find(*it) == ans.npos) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << ans << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}
