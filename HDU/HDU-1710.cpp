#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

struct tree {
	// 数据域
    int data;
	// 指针域
    tree *LeftChild, *RightChild;
    tree(): data(INF), LeftChild(NULL), RightChild(NULL) {}
};

int n;
int cnt;
tree *root;
// 前序遍历
int front[maxn];
// 中序遍历
int mid[maxn];

// 初始化二叉树
void init() {
    cnt = 0;
    root = new tree;
    mem(front, 0);
    mem(mid, 0);
}

// 找树根
int findroot(int lfront, int rfront, int lmid, int rmid) {
    int index;
    for (int i = lmid; i <= rmid; ++i) {
        if (mid[i] == front[lfront]) {
            index = i;
        }
    }
    return index;
}

// 添加节点
void addtree(int lfront, int rfront, int lmid, int rmid, tree *r) {
    int index = findroot(lfront, rfront, lmid, rmid);
    r -> data = mid[index];
    if (lmid <= index - 1) {
        r -> LeftChild = new tree;
        addtree(lfront + 1, index - lmid, lmid, index - 1, r -> LeftChild);
    }
    if (index + 1 <= rmid) {
        r -> RightChild = new tree;
        addtree(lfront + 1 + index - lmid, rfront, index + 1, rmid, r -> RightChild);
    }
}

// 后序遍历递归输出
void behind(tree *v) {
    if (v == NULL) {
        return;
    }
    behind(v -> LeftChild);
    behind(v -> RightChild);
    if (cnt++) {
        printf(" ");
    }
    printf("%d", v -> data);
}

// 清除二叉树
void remove(tree *u) {
    if (u == NULL) {
        return;
    }
    remove(u -> LeftChild);
    remove(u -> RightChild);
    delete u;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d", &n)) {
        init();
        for (int i = 1; i <= n; ++i) {
            read(front[i]);
        }
        for (int i = 1; i <= n; ++i) {
            read(mid[i]);
        }
        addtree(1, n, 1, n, root);
        behind(root);
        printf("\n");
        remove(root);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
