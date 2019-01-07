#include <iostream>
using namespace std;
// 根据题意模拟
int main() {
    ios::sync_with_stdio(0);
    const int sta = 3;
    int N;
    cin >> N;
    while (N--) {
        int a;
        cin >> a;
        long long res = sta;
        for (int i = 0;i < a;++i) {
            res = (res - 1) * 2;
        }
        cout << res << endl;
    }
    return 0;
}
