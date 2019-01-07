#include <iostream>
using namespace std;
// 类斐波那契数列
int main() {
    ios::sync_with_stdio(0);
    long long num[55] = {1,1,2,3};
    for (int i = 4;i < 55;++i) {
        num[i] = num[i - 1] + num[i - 3];
    }
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cout << num[n] << endl;
    }
    return 0;
}
