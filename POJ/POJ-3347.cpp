#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct Square {
	double Left, Right, Length;
};

const int maxn = 1e2 + 5;
const double eps = 1e-8;

int N;
Square squares[maxn];

int main(int argc, char *argv[]) {
	while (~scanf("%d", &N) && N) {
		for (int i = 1; i <= N; ++i) {
			scanf("%lf", &squares[i].Length);
			squares[i].Left = 0;
			// 枚举定位左边界
			for (int j = 1; j < i; ++j) {
				squares[i].Left = max(squares[i].Left, squares[j].Right - fabs(squares[i].Length - squares[j].Length) / sqrt(2.0));
			}
			// 计算右边界
			squares[i].Right = squares[i].Left + squares[i].Length * sqrt(2.0);
		}
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j < i; ++j) {
				// 若正方形i边长大于正方形j边长且正方形i左边界小于正方形j右边界则正方形j的右边界为正方形i的左边界
				if (squares[i].Length > squares[j].Length && squares[i].Left < squares[j].Right) {
					squares[j].Right = squares[i].Left;
				}
				// 若正方形i边长小于正方形j边长且正方形i左边界小于正方形j右边界则正方形i的左边界为正方形j的右边界
				if (squares[i].Length < squares[j].Length && squares[i].Left < squares[j].Right) {
					squares[i].Left = squares[j].Right;
				}
			}
		}
		// 行末无空格
		bool First = true;
		for (int i = 1; i <= N; ++i) {
			if (squares[i].Left < squares[i].Right - eps) {
				First ? First = false : printf(" ");
				printf("%d", i);
			}
		}
		printf("\n");
	}
	return 0;
}

