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
const int maxn = 4e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

// 二叉树
struct tree {
	// 数据域
    ll data;
	// 指针域
    tree *LeftChild, *RightChild;
    tree(): data(INF), LeftChild(NULL), RightChild(NULL) {}
};

bool fail;
tree *root;
vector<ll> ans;

// 添加节点
void addtree(ll x, string index) {
    tree *f = root;
    if (index == "") {
        f -> data = x;
        return;
    }
    for (int i = 0; i < int(index.size()); ++i) {
        if (index[i] == 'L') {
            if (f -> LeftChild == NULL) {
                f -> LeftChild = new tree;
            }
            f = f -> LeftChild;
        }
        else if (index[i] == 'R') {
            if (f -> RightChild == NULL) {
                f -> RightChild = new tree;
            }
            f = f -> RightChild;
        }
    }
	// 不可建树
    if (f -> data != INF) {
        fail = 1;
    }
    f -> data = x;
}

// 层序遍历
bool find() {
    queue<tree*> que;
    ans.clear();
    que.push(root);
    while (!que.empty()) {
        tree *temp = que.front();
        que.pop();
		// 不可建树
        if (temp -> data == INF) {
            return 0;
        }
        ans.pb(temp -> data);
        if (temp -> LeftChild != NULL) {
            que.push(temp -> LeftChild);
        }
        if (temp -> RightChild != NULL) {
            que.push(temp -> RightChild);
        }
    }
    return 1;
}

// 销毁树
void remove (tree *u) {
    if (u == NULL) {
        return;
    }
    remove(u -> LeftChild);
    remove(u -> RightChild);
    delete u;
}

// 数据读取
bool read() {
    string Input;
    ll num;
    string str;
    remove(root);
    root = NULL;
    fail = 0;
    while (cin >> Input) {
        if (root == NULL) {
            root = new tree;
        }
        num = 0;
        str.clear();
        if (Input == "()") {
            return 1;
        }
        int i;
        for (i = 1; Input[i] != ','; ++i) {
            num = num * 10 + Input[i] - '0';
        }
        ++i;
        for (; Input[i] != ')'; ++i) {
            str += Input[i];
        }
        addtree(num, str);
    }
    return 0;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (read()) {
        if (find() && !fail) {
            for (int i = 0; i < int(ans.size()); ++i) {
                if (i) {
                    cout << " ";
                }
                cout << ans[i];
            }
            cout << endl;
        }
        else {
            cout << "not complete" << endl;
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
