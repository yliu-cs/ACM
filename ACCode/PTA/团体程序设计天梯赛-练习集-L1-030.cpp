#include <stdio.h>
#include <iostream>
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

struct student {
    bool Gender;
    string Name;
    bool Vis;
}q[51];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        q[i].Vis = 0;
        cin >> q[i].Gender >> q[i].Name;
    }
    for (int i = 0; i < N; ++i) {
        bool first;
        if (q[i].Vis == 0) {
            first = q[i].Gender;
            cout << q[i].Name << " ";
            q[i].Vis = 1;
            for (int j = N - 1; j > i; --j) {
                if (q[j].Gender != first && q[j].Vis == 0) {
                    cout << q[j].Name << endl;
                    q[j].Vis = 1;
                    break;
                }
            }
        }
    }
    return 0;
}
