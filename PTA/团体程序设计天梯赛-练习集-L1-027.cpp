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

bool cmp(int a, int b) {
    return a > b;
}

bool vis[10] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[13], index[13], book = 0;
    string s;
    cin >> s;
    for (int i = 0; i < 11; ++i) {
        int a = s[i] - '0';
        if (vis[a] == 0) {
            arr[book++] = a;
            index[i] = a;
            vis[a] = 1;
        }
        else {
            index[i] = a;
        }
    }
    sort(arr, arr + book, cmp);
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < book; ++j) {
            if (index[i] == arr[j]) {
                index[i] = j;
                break;
            }
        }
    }
    cout << "int[] arr = new int[]{";
    for (int i = 0; i < book; ++i) {
        cout << arr[i];
        if (i != book - 1) {
            cout << ",";
        }
    }
    cout << "};" << endl;
    cout << "int[] index = new int[]{";
    for (int i = 0; i < 11; ++i) {
        cout << index[i];
        if (i != 10) {
            cout << ",";
        }
    }
    cout << "};";
    return 0;
}
