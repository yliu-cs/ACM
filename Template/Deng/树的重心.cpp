/*
树的重心也叫树的质心。对于一棵树n个节点的无根树，找到一个点，使得把树变成以该点为根的有根树时，最大子树的结点数最小。换句话说，删除这个点后最大连通块（一定是树）的结点数最小。

和树的最大独立问题类似，先任选一个结点作为根节点，把无根树变成有根树，然后设d(i)表示以i为根的子树的结点的个数。不难发现d(i)=∑d(j)+1，j∈s（i）。s（i）为i结点的所有儿子结点的编号的集合。程序也十分简单：只需要DFS一次，在无根树有根数的同时计算即可，连记忆化都不需要——因为本来就没有重复计算。 
那么，删除结点i后，最大的连通块有多少个呢？结点i的子树中最大有max{d（j）}个结点，i的“上方子树”中有n-d（i）个结点， 
 
如图这样，在动态规划的过程中就可以随便找出树的重心了。
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <deque>
#include <stdlib.h>
#include <bitset>

using namespace std;

#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define maxn 10
#define eps 0.00000001
#define M 1e9 + 7

vector<int> tree[maxn];//tree[i]是与i相邻的点
int d[maxn + 5]; //以i为根的子树的节点个数
int minNode;
int minBalance;
int n;

void dfs(int node, int parent) {//自己， 父节点
    d[node] = 1;// 自身
    int maxSubTree = 0;//最大子树节点个数
    for (int i = 0; i < (int)tree[node].size(); i ++) {
        int son = tree[node][i];//子树
        if(son != parent) {
            dfs(son, node);
            d[node] += d[son];//node的节点数加上son的节点个数
            maxSubTree = max(maxSubTree, d[son]);//比较更大的子树节点个数
        }
    }
    maxSubTree = max(maxSubTree, n - d[node]);
    if(maxSubTree < minBalance) {
        minBalance = maxSubTree;
        minNode = node;
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for (int i = 1; i < n; i ++) {
        int s, e;
        scanf("%d %d", &s, &e);
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
    minNode = 0;
    minBalance = INF;
    dfs(1, 0);
    printf("%d %d\n", minNode, minBalance);
    return 0;
}

// 数组模拟邻接表版

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <deque>
#include <stdlib.h>
#include <bitset>

using namespace std;

#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define maxn 100005
#define eps 0.00000001
#define M 1e9 + 7

struct Edge{
    int s, e;
    Edge() {}
    Edge(int _s, int _e) {
        s = _s;
        e = _e;
    }
}edge[2 * maxn];

int Next[maxn * 2], pre[maxn * 2], tot, ans[maxn], d[maxn];
int n, minBalance, minNode;

void add(int s, int e) {
    tot ++;
    Next[tot] = pre[s]; pre[s] = tot;
    edge[tot].s = s;
    edge[tot].e = e;
}

void init() {
    for (int i = 0; i < 2 * maxn; i ++)
        Next[i] = pre[i] = -1;
}

void dfs(int node, int parent) {
    d[node] = 1;
    int maxSubTree = 0;
    for (int i = pre[node]; i != -1; i = Next[i]) {
        int son = edge[i].e;
        if(son == parent) continue;
        dfs(son, node);
        d[node] += d[son];
        maxSubTree = max(maxSubTree, d[son]);
    }
    maxSubTree = max(maxSubTree, n - d[node]);
    if(maxSubTree < minBalance) {
        minBalance = maxSubTree;
        minNode = node;
    }
}


int main(int argc, const char * argv[]) {

    scanf("%d", &n);
    tot = 0;
    init();
    for (int i = 1; i < n; i ++) {
        int s, e;
        scanf("%d %d", &s, &e);
        add(s, e);
        add(e, s);
    }
    minBalance = INF;
    minNode = 0;
    tot = 0;
    dfs(1, 0);

    return 0;
}
