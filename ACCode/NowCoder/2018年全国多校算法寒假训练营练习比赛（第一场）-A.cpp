#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
using namespace std;
 
bool cmp(int a,int b) {
    return a > b;
}
 
int main() {
    ios::sync_with_stdio(0);
    const int BasicMax = 1010;
    int n,m;
    while (cin >> n >> m) {
        int *p,*k,**NumOfk;
        p = new int[n];
        k = new int[n];
        NumOfk = new int*[n];
        for (int i = 0;i < n;++i) {
            NumOfk[i] = new int[BasicMax];
        }
        for (int i = 0;i < n;++i) {
            for (int j = 0;j < BasicMax;++j) {
                NumOfk[i][j] = 0;
            }
        }
        for (int i = 0;i < n;++i) {
            cin >> p[i] >> k[i];
            for (int j = 0;j < k[i];++j) {
                cin >> NumOfk[i][j];
            }
        }
        int *q;
        q = new int[m];
        double *b;
        b = new double[m];
        for (int i = 0;i < m;++i) {
            cin >> q[i] >> b[i];
            for (int j = 0;j < i;++j) {
                if(q[i] == q[j] && b[i] < b[j]) {
                    q[i] = -1;
                    b[i] = 0;
                }
                else if (q[i] == q[j] && b[i] > b[j]) {
                    q[j] = -1;
                    b[j] = 0;
                }
            }
        }
        double *w,*Sum;
        w = new double[n];
        Sum = new double[n];
        for (int i = 0;i < n;++i) {
            Sum[i] = 1;
        }
        for (int h = 0;h < n;++h) {
            for (int j = 0;j < k[h];++j) {
                for (int i = 0;i < m;++i) {
                    if (NumOfk[h][j] == q[i]) {
                        Sum[h] += b[i];
                        break;
                    }
                }
            }
        }
        for (int i = 0;i < n;++i) {
            w[i] = p[i] * Sum[i];
        }
        sort(w, w + n, cmp);
        cout << setiosflags(ios::fixed) << setprecision(4) << w[0] << endl;
    }
    return 0;
}
