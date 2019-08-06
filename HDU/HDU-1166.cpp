#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int INF = 0x3f3f3f3f;
const int maxn = 5e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

int Sum[maxn << 2], Lazy[maxn << 2];

// 更新节点信息
void PushUp(int root) {
    Sum[root] = Sum[root << 1] + Sum[root << 1 | 1];
}

void PushDown(int root, int leftnum, int rightnum) {
    if (Lazy[root]) {
        // 下推标记,假设num[x]+=value
        Lazy[root << 1] += Lazy[root];
        Lazy[root << 1 | 1] += Lazy[root];
        // 修改子节点值
        Sum[root << 1] += Lazy[root] * leftnum;
        Sum[root << 1 | 1] += Lazy[root] * rightnum;
        // 清除节点标记
        Lazy[root] = 0;
    }
}

// 创建树
void Build(int left, int right, int root) {
    Lazy[root] = 0;
    if (left == right) {
        read(Sum[root]);
        return;
    }
    int mid = (left + right) >> 1;
    // 创建左右子树
    Build(left, mid, root << 1);
    Build(mid + 1, right, root << 1 | 1);
    // 更新节点信息
    PushUp(root);
}

// 单点修改
void PointUpdate(int pos, int value, int left, int right, int root) {
    // 修改叶子节点
    if (left == right) {
        // 假设num[x]+=value
        Sum[root] += value;
        return;
    }
    int mid = (left + right) >> 1;
    // 判断调用左子树还是右子树
    if (pos <= mid) {
        PointUpdate(pos, value, left, mid, root << 1);
    }
    else {
        PointUpdate(pos, value, mid + 1, right, root << 1 | 1);
    }
    // 更新信息
    PushUp(root);
}

// 区间修改
void IntervalUpdate(int operateleft, int operateright, int value, int left, int right, int root) {
    if (operateleft <= left && operateright >= right) {
        // 假设num[x]+=value
        Sum[root] += value * (right - left + 1);
        Lazy[root] += value;
        return;
    }
    int mid = (left + right) >> 1;
    PushDown(root, mid - left + 1, right - mid);
    // 判断左右字数是否和操作区间有交集
    if (operateleft <= mid) {
        IntervalUpdate(operateleft, operateleft, value, left, mid, root << 1);
    }
    if (operateright > mid) {
        IntervalUpdate(operateleft, operateleft, value, left, mid, root << 1 | 1);
    }
    PushUp(root);
}

// 区间查询
int Query(int operateleft, int operateright, int left, int right, int root) {
    if (operateleft <= left && operateright >= right) {
        return Sum[root];
    }
    int mid = (left + right) >> 1;
    PushDown(root, mid - left + 1, right - mid);
    int ans = 0;
    if (operateleft <= mid) {
        ans += Query(operateleft, operateright, left, mid, root << 1);
    }
    if (operateright > mid) {
        ans += Query(operateleft, operateright, mid + 1, right, root << 1 | 1);
    }
    return ans;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    int t;
    read(t);
    for (int Case = 1; Case <= t; ++Case) {
        int n;
        read(n);
        Build(1, n, 1);
        char order[10];
        int x, y;
        printf("Case %d:\n", Case);
        scanf("%s", &order);
        while (strcmp(order, "End")) {
            read(x); read(y);
            if (strcmp(order, "Add") == 0) {
                PointUpdate(x, y, 1, n, 1);
            }
            else if (strcmp(order, "Sub") == 0) {
                PointUpdate(x, -y, 1, n, 1);
            }
            else if (strcmp(order, "Query") == 0) {
                printf("%d\n", Query(x, y, 1, n, 1));
            }
            scanf("%s", order);
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
//    fclose(stdout);
//    system("gedit out.txt");
#endif
    return 0;
}
