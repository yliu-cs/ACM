#include <iostream>
using namespace std;
int main() {
    int n, k, temp, sum = 0;
    cin >> n >> k;
    int *num;
    num = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        if (i == k - 1) {
            temp = num[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (num[i] >= temp && num[i] != 0) {
            sum++;
        }
    }
    cout << sum;
    return 0;
}