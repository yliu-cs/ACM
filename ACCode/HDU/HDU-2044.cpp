#include <iostream>
using namespace std;
// 斐波那契数列
int main() {
    long long N,num[50] = {0,1,2};
    for (int i = 3;i < 50;++i) {
        num[i] = num[i - 1] + num[i - 2];
    }
    cin >> N;
    while (N--) {
        int a,b;
        cin >> a >> b;
        cout << num[b - a] << endl;
    }
    return 0;
}
