#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1010;
const double eps = 1e-5;
const double e = 2.718281828459;

int n, m, num;
int cnt = 0;
// 二叉树数组
int tree[maxn];

// 判断插入数字和父节点的大小关系
void Judge_change_tree(int self) {
    // 若搜索到根节点则返回
    if (self == 1) {
        return;
    }
    // 若根节点下标为0：设节点下标为n，此节点左孩子下标为2*n+1,右孩子下标为2*n+2
    // 若根节点下标为1：设节点下标为n，此节点左孩子下标为2*n,右孩子下标为2*n+1
    // 此处逆推寻找父节点的数组下标
    int parent;
    if (self % 2) {
        parent = (self - 1) >> 1;
    }
    else {
        parent = self >> 1;
    }
    // 若父节点大则交换并继续向根节点方向判断替换
    if (tree[self] < tree[parent]) {
        int temp = tree[self];
        tree[self] = tree[parent];
        tree[parent] = temp;
        Judge_change_tree(parent);
    }
}

void Build_tree() {
    // 将新插入的数放到最后
    tree[++cnt] = num;
    Judge_change_tree(cnt);
}

void Judge_Output(string be_judge_str) {
    int len = be_judge_str.length();
    int x = 0, y = 0;
    bool x_pm_flag = 0, y_pm_flag= 0;
    bool number_changr_flag= 1;
    string x_str, y_str;
    for (int i = 0; i < len; ++i) {
        if (be_judge_str[i] >= '0' && be_judge_str[i] <= '9') {
            if (number_changr_flag) {
                if (i != 0 && be_judge_str[i - 1] == '-') {
                    x_pm_flag = 1;
                }
                x = x * 10 + be_judge_str[i] - '0';
                x_str += be_judge_str[i];
            }
            else {
                if (i != 0 && be_judge_str[i - 1] == '-') {
                    y_pm_flag = 1;
                }
                y = y * 10 + be_judge_str[i] - '0';
                y_str += be_judge_str[i];
            }
        }
        else {
            if (i != 0) {
                number_changr_flag = 0;
            }
            continue;
        }
    }
    if (x_pm_flag) {
        x = -x;
        string x_pm_temp;
        x_pm_temp = '-';
        x_pm_temp += x_str;
        x_str = x_pm_temp;
    }
    if (y_pm_flag) {
        y = -y;
        string y_pm_temp;
        y_pm_temp = '-';
        y_pm_temp += y_str;
        y_str = y_pm_temp;
    }
    if (be_judge_str == (x_str + " is the root")) {
        if (x == tree[1]) {
            cout << "T" << endl;
        }
        else {
            cout << "F" << endl;
        }
    }
    else if (be_judge_str == (x_str + " and " + y_str + " are siblings")) {
        bool brother_flag = 0;
        for (int i = 2; i <= n; i += 2) {
            if (tree[i] == x && tree[i + 1] == y) {
                brother_flag = 1;
                break;
            }
            if (tree[i] == y && tree[i + 1] == x) {
                brother_flag = 1;
                break;
            }
        }
        if (brother_flag) {
            cout << "T" << endl;
        }
        else {
            cout << "F" << endl;
        }
    }
    else if (be_judge_str == (x_str + " is the parent of " + y_str)) {
        bool father_flag = 0;
        for (int i = 1; i <= n; ++i) {
            if (tree[i] == x && (tree[i * 2] == y || tree[i * 2 + 1] == y)) {
                father_flag = 1;
                break;
            }
        }
        if (father_flag) {
            cout << "T" << endl;
        }
        else {
            cout << "F" << endl;
        }
    }
    else {
        bool son_flag = 0;
        for (int i = 1; i <= n; ++i) {
            if (tree[i] == y && (tree[i * 2] == x || tree[i * 2 + 1] == x)) {
                son_flag = 1;
                break;
            }
        }
        if (son_flag) {
            cout << "T" << endl;
        }
        else {
            cout << "F" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    mem(tree, INF);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        Build_tree();
    }
    cin.get();
    while (m--) {
        string ask_str;
        getline(cin, ask_str);
        Judge_Output(ask_str);
    }
    return 0;
}
