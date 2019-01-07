#include <bits/stdc++.h>

using namespace std;

const int N = 303;

int n;
bool eq[N][N];
int dp[N][N];
string s[N];

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    cin >> n;
    int allsum = n - 1;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        allsum += s[i].size();
    }

    for (int i = 0; i < n; ++i) {
        eq[i][i] = true;
        for (int j = 0; j < i; ++j) {
            eq[i][j] = eq[j][i] = s[i] == s[j];
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (eq[i][j]) {
                if (i + 1 < n && j + 1 < n)
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                else
                    dp[i][j] = 1;
            }
        }
    }

    int ans = allsum;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; i + j < n; ++j) {
            sum += s[i + j].size();
            int cnt = 1;
            for (int pos = i + j + 1; pos < n; ++pos) {
                if (dp[i][pos] > j) {
                    ++cnt;
                    pos += j;
                }
            }
            int cur = allsum - sum * cnt + (j + 1) * cnt - j * cnt;
            if (cnt > 1 && ans > cur) {
                ans = cur;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
