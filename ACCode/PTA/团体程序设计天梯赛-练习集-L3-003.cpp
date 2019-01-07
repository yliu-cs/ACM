#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1010;
const double eps = 1e-5;
const double e = 2.718281828459;

int n, k, num;
int cnt = 0;
int course[maxn];
int pre[maxn];
int isroot[maxn];

bool cmp(int a,int b) {
	return a > b;
}

void Init() {
	mem(course, 0);
	mem(isroot, 0);
	for (int i = 0; i <= n; ++i) {
		pre[i] = i;
	}
}

int Find(int x) {
	int r = x;
	while (pre[r] != r) {
		r = pre[r];
	}
	return r;
}

void Join(int x, int y) {
	int xx = Find(x);
	int yy = Find(y);
	if (xx != yy) {
		pre[xx] = yy;
	}
}

void Get_information() {
	cin >> n;
	Init();
	for (int i = 1;i <= n; ++i) {
		scanf("%d:", &k);
		for (int j = 0; j < k; ++j) {
			cin >> num;
			if (course[num] == 0) {
				course[num] = i;
			}
			Join(i, Find(course[num]));
		}
	}
}

void Work() {
	for (int i = 1; i <= n; ++i) {
		isroot[Find(i)]++;
	}
	for (int i = 1; i <= n; ++i) {
		if (isroot[i] != 0) {
			cnt++;
		}
	}
	cout << cnt << endl;
	sort(isroot, isroot + maxn, cmp);
	for (int i = 0; i < cnt; ++i) {
		cout << isroot[i];
		if (i != cnt - 1) {
			cout << " ";
		}
	}
}

int main() {
    Get_information();
    Work();
    return 0;
}
