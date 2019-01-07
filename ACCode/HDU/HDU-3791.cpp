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

// 二叉树节点
struct tree {
	// 数据域
    int data;
	// 指针域
    tree *LeftChild, *RightChild;
    tree(): data(INF), LeftChild(NULL), RightChild(NULL) {}
};

bool flag;
tree *standardroot;
tree *judgeroot;

// 按照二叉搜索树规则添加节点
void addvertex(tree *u, int data) {
    if ((u -> data) == INF) {
        u -> data = data;
        return;
    }
    if (data < u -> data) {
        if (u -> LeftChild == NULL) {
            u -> LeftChild = new tree;
        }
        addvertex(u -> LeftChild, data);
    }
    else if(data > u -> data) {
        if (u -> RightChild == NULL) {
            u -> RightChild = new tree;
        }
        addvertex(u -> RightChild, data);
    }
}

// 判断是否能够构成同一个二叉树
void check(tree *f, tree *g) {
    if (f -> data != g -> data) {
        flag = 0;
        return;
    }
    if (f -> LeftChild && g -> LeftChild) {
        check(f -> LeftChild, g -> LeftChild);
    }
    else if ((f -> LeftChild == NULL && g -> LeftChild) || (f -> LeftChild && g -> LeftChild)) {
        flag = 0;
    }
    if (!flag) {
        return;
    }
    if (f -> RightChild && g -> RightChild) {
        check(f -> RightChild, g -> RightChild);
    }
    else if ((f -> RightChild == NULL && g -> RightChild) || (f -> RightChild && g -> RightChild)) {
        flag = 0;
    }
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
//    freopen("out.txt", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n)) {
        standardroot = new tree;
        string standard;
        cin >> standard;
        for (int i = 0; i < int(standard.size()); ++i) {
            addvertex(standardroot, int(standard[i] - '0'));
        }
        while (n--) {
            string judge;
            cin >> judge;
            judgeroot = new tree;
            for (int i = 0; i < int(judge.size()); ++i) {
                addvertex(judgeroot, int(judge[i] - '0'));
            }
            flag = 1;
            check(standardroot, judgeroot);
            if (flag) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
            remove(judgeroot);
        }
        remove(standardroot);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
//    fclose(stdout);
//    system("gedit out.txt");
#endif
    return 0;
}
