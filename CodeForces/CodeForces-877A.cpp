//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
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
#include <set>
#include <map>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double e = 2.718281828459;

string str;

bool judge(int x) {
	if (str[x] == 'D') {
		if (str[x + 1] != '\0' && str[x + 1] == 'a') {
			if (str[x + 2] != '\0' && str[x + 2] == 'n') {
				if (str[x + 3] != '\0' && str[x + 3] == 'i') {
					if (str[x + 4] != '\0' && str[x + 4] == 'l') {
						return 1;
					}
				}
			}
		}
	}
	else if (str[x] == 'O') {
		if (str[x + 1] != '\0' && str[x + 1] == 'l') {
			if (str[x + 2] != '\0' && str[x + 2] == 'y') {
				if (str[x + 3] != '\0' && str[x + 3] == 'a') {
					return 1;
				}
			}
		}
	}
	else if (str[x] == 'S') {
		if (str[x + 1] != '\0' && str[x + 1] == 'l') {
			if (str[x + 2] != '\0' && str[x + 2] == 'a') {
				if (str[x + 3] != '\0' && str[x + 3] == 'v') {
					if (str[x + 4] != '\0' && str[x + 4] == 'a') {
						return 1;
					}
				}
			}
		}
	}
	else if (str[x] == 'A') {
		if (str[x + 1] != '\0' && str[x + 1] == 'n') {
			if (str[x + 2] != '\0' && str[x + 2] == 'n') {
				return 1;
			}
		}
	}
	else if (str[x] == 'N') {
		if (str[x + 1] != '\0' && str[x + 1] == 'i') {
			if (str[x + 2] != '\0' && str[x + 2] == 'k') {
				if (str[x + 3] != '\0' && str[x + 3] == 'i') {
					if (str[x + 4] != '\0' && str[x + 4] == 't') {
						if (str[x + 5] != '\0' && str[x + 5] == 'a') {
							return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    cin >> str;
    for (int i = 0; str[i] != '\0'; ++i) {
    	if (judge(i)) {
    		cnt++;
		}
	}
	if (cnt == 1) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
    return 0;
}