#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int res;
    res = n + 2;
    if (res > 7) {
        res -= 7;
    }
    cout << res;
    return 0;
}
