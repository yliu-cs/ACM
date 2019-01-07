#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;
const int maxn = 100010;
bool F[maxn];
bool vis[maxn];
int main() {
    memset(F, 0, sizeof(F));
    memset(vis, 0, sizeof(vis));
    int n;
    cin >> n;
    bool flag = 0;
    while (n--) {
        int k;
        cin >> k;
        int temp = k;
        while (temp--) {
            int a;
            cin >> a;
            if (k > 1) {
                F[a] = 1;
            }
        }
    }
    int m;
    cin >> m;
    while (m--) {
        int b;
        cin >> b;
        if (!F[b] && !vis[b]) {
            if (!flag) {
                if (b > 9999) {
                    printf("%d", b);
                }
                else if (b > 999) {
                    printf("0%d", b);
                }
                else if (b > 99) {
                    printf("00%d", b);
                }
                else if (b > 9) {
                    printf("000%d", b);
                }
                else {
                    printf("0000%d", b);
                }
                flag = 1;
            }
            else {
                cout << " ";
                if (b > 9999) {
                    printf("%d", b);
                }
                else if (b > 999) {
                    printf("0%d", b);
                }
                else if (b > 99) {
                    printf("00%d", b);
                }
                else if (b > 9) {
                    printf("000%d", b);
                }
                else {
                    printf("0000%d", b);
                }
            }
            vis[b] = 1;
        }
    }
    if (!flag) {
        cout << "No one is handsome";
    }
    return 0;
}
