#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double e = 2.718281828459;

int n, num;
// 二叉树数组
// 若根节点下表为0：设节点下表为n，此节点左孩子下标为2*n+1,右孩子下标为2*n+2
// 若根节点下表为1：设节点下表为n，此节点左孩子下标为2*n,右孩子下标为2*n+1
int tree[maxn];

// 根据题目要求递归建立二叉树
void Build_tree(int a) {
    // 若节点为空，则将数值放置在此
    if (tree[a] == -1) {
        tree[a] = num;
    }
    // 小于父节点在右侧寻找
    else if (num < tree[a]) {
        // 下标计算可以利用位运算
        Build_tree(a * 2 + 2);
    }
    // 大于在左侧寻找
    else {
        // 下标计算可以利用位运算
        Build_tree(a * 2 + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    mem(tree, -1);
    for (int i = 0; i < n; ++i) {
        cin >> num;
        // 从根节点开始寻找数值应该插入位置
        Build_tree(0);
    }
    bool flag = 1;
    int cnt = 1;
    for (int i = 0; cnt <= n; ++i) {
        // 层序遍历中若出现空节点则不是完全二叉树，改变判断bool变量值
        if (tree[i] == -1) {
            flag = 0;
        }
        // 按照要求输出层序遍历结果
        else {
            if (cnt == n) {
                cout << tree[i] << endl;
            }
            else {
                cout << tree[i] << " ";
            }
            cnt++;
        }
    }
    // 根据判断是否为完全二叉树的bool变量输出结果
    if (flag) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}

