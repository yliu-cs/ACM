#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num_1, num_2;
    cin >> num_1 >> num_2;
    int n;
    cin >> n;
    int res_1 = 0, res_2 = 0;
    bool flag_1 = 0, flag_2 = 0;
    bool flag = 0;
    while (n--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b == (a + c) && d == (a + c)) {
            continue;
        }
        if (flag) {
            continue;
        }
        if (b == (a + c) && d != (a + c)) {
            res_1++;
        }
        else if (b != (a + c) && d == (a + c)) {
            res_2++;
        }
        if (res_1 > num_1) {
            flag_1 = 1;
            flag = 1;
        }
        if (res_2 > num_2) {
            flag_2 = 1;
            flag = 1;
        }
    }
    if (flag_1) {
        cout << "A" << endl;
        cout << res_2;
    }
    else {
        cout << "B" << endl;
        cout << res_1;
    }
    return 0;
}
