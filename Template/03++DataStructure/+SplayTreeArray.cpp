const int inf = "Edit"
const int maxn = "Edit";

class SplayTree {
  public:
    // rt:Splay Tree根节点
    int rt;
    // son[i][0]:i节点的左孩子，son[i][0]:i节点的右孩子
    int son[maxn][2];
    // fa[i]:i节点的父节点
    int fa[maxn];
    // val[i]:i节点的权值
    int val[maxn];
    // sz[i]:以i节点为根的Splay Tree的节点数(包含自身)
    int sz[maxn];
    // 惰性标记数组
    bool lazy[maxn];

    void Push(int o) {
      sz[o] = sz[son[o][0]] + sz[son[o][1]] + 1;
    }

    void Pull(int o) {
      if (lazy[o]) {
        std::swap(son[o][0], son[o][1]);
        if (son[o][0]) lazy[son[o][0]] ^= 1;
        if (son[o][1]) lazy[son[o][1]] ^= 1;
        lazy[o] = 0;
      }
    }

    // 判断o节点是其父节点的左孩子还是右孩子
    bool Get(int o) {
      return son[fa[o]][1] == o;
    }

    // 旋转节点o
    void Rotate(int o) {
      int p = fa[o], q = fa[p], ck = Get(o);
      Pull(p); Pull(o);
      son[p][ck] = son[o][ck ^ 1];
      fa[son[p][ck]] = fa[o];
      son[o][ck ^ 1] = fa[o];
      fa[p] = o;
      fa[o] = q;
      if (q) son[q][p == son[q][1]] = o;
      Push(p); Push(o);
    }

    // 旋转o节点到节点tar
    void Splay(int o, int tar = 0) {
      for (int cur = fa[o]; (cur = fa[o]) != tar; Rotate(o)) {
        Pull(fa[cur]); Pull(cur); Pull(o);
        if (fa[cur] != tar) {
          if (Get(o) == Get(cur)) Rotate(cur);
          else Rotate(o);
        }
      }
      if (!tar) rt = o;
    }

    // 获取以r为根节点Splay Tree中的第k大个元素在Splay Tree中的位置
    int Kth(int r, int k) {
      Pull(r);
      int tmp = sz[son[r][0]] + 1;
      if (tmp == k) return r;
      if (tmp > k) return Kth(son[r][0], k);
      else return Kth(son[r][1], k - tmp);
    }

    // 获取Splay Tree中以o为根节点子树的最小值位置
    int GetMin(int o) {
      Pull(o);
      while (son[o][0]) {
        o = son[o][0];
        Pull(o);
      }
      return o;
    }

    // 获取Splay Tree中以o为根节点子树的最大值位置
    int GetMax(int o) {
      Pull(o);
      while (son[o][1]) {
        o = son[o][1];
        Pull(o);
      }
      return o;
    }

    // 求节点o的前驱节点
    int GetPath(int o) {
      Splay(o, rt);
      int cur = son[rt][0];
      while (son[cur][1]) cur = son[cur][1];
      return cur;
    }

    // 求节点Y的后继节点
    int GetNext(int o) {
      Splay(o, rt);
      int cur = son[rt][1];
      while (son[cur][0]) cur = son[cur][0];
      return cur;
    }

    // 翻转Splay Tree中l~r区间
    void Reverse(int l, int r) {
      int o = Kth(rt, l), Y = Kth(rt, r);
      Splay(o, 0); Splay(Y, o);
      lazy[son[Y][0]] ^= 1;
    }

    // 建立Splay Tree
    void Build(int l, int r, int o) {
      if (l > r) return;
      int m = (l + r) >> 1;
      Build(l, m - 1, m);
      Build(m + 1, r, m);
      fa[m] = o;
      val[m] = m - 1;
      lazy[m] = 0;
      Push(m);
      if (m < o) son[o][0] = m;
      else son[o][1] = m;
    }

    // 输出Splay Tree
    void Print(int o) {
      Pull(o);
      if (son[o][0]) Print(son[o][0]);
      // 哨兵节点判断
      if (val[o] != -inf && val[o] != inf) printf("%d ", val[o]);
      if (val[son[o][1]]) Print(son[o][1]);
    }
};