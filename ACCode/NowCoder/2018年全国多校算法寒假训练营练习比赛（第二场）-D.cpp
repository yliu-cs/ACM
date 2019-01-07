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
  
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int maxn = 1000000;
  
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,*num;
    cin >> n;
    num = new int[n];
    for (int i = 0;i < n;++i) {
        cin >> num[i];
    }
    int max,book;
    for (int i = 0;i < n;++i) {
        max = num[i];
        book = 1;
        for (int j = i + 1;j < n;++j) {
            if (num[j] >= max) {
                max = num[j];
                book++;
            }
        }
        if (book >= 30) {
            break;
        }
    }
    if (book >= 30) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
    return 0;
}
