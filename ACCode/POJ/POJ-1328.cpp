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
const int maxn = 1010;
const double eps = 1e-5;
const double e = 2.718281828459;

struct scope_x {
	double x1;
	double x2;
	scope_x() {
		x1 = 0;
		x2 = 0;
	}
}scope[maxn];

int n;
double d;
int case_cnt = 0; 
int output_cnt = 0;
double input_x, input_y;
double judge_temp;
bool fal_flag;

bool cmp(scope_x a, scope_x b) {
	return a.x2 < b.x2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> d) {
    	if (n == 0 && d == 0) {
    		break;
		}
    	fal_flag = 1;
    	output_cnt = 0;
    	for (int i = 0; i < n; ++i) {
    		cin >> input_x >> input_y;
    		if (input_y < 0 || input_y > d) {
    			fal_flag = 0;
			}
    		scope[i].x1 = input_x - sqrt(d * d - input_y * input_y);
    		scope[i].x2 = input_x + sqrt(d * d - input_y * input_y);
		}
		sort(scope, scope + n, cmp);
		judge_temp = scope[0].x2;
		output_cnt++;
		for (int i = 1; i < n; ++i) {
			if (scope[i].x1 > judge_temp) {
				judge_temp = scope[i].x2;
				output_cnt++;
			}
		}
		if (fal_flag) {
    		cout << "Case " << ++case_cnt << ": " << output_cnt << endl;
		}
		else {
    		cout << "Case " << ++case_cnt << ": " << -1 << endl;
		}
	}
    return 0;
}
