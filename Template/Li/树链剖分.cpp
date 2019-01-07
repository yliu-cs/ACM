// 树链剖分
struct edge {
    int v, next;
}e[N<<1];
int tot, head[N], id;
int pos[N], dep[N], top[N], fa[N], son[N], sz[N];
int val[N], num[N];
void add_edge(int u, int v)
{
    e[tot].v = v; e[tot].next = head[u]; head[u] = tot++;
}
void init()
{
    tot = 0; id = 0;
    memset(head, -1, sizeof head);
}
void dfs(int u, int pre, int d)
{
    dep[u] = d; sz[u] = 1; fa[u] = pre; son[u] = -1;
    for (int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == pre) continue;
        dfs(v, u, d + 1);
        sz[u] += sz[v];
        if (son[u] == -1 || sz[son[u]] < sz[v])
            son[u] = v;
    }
}
void dfs1(int u, int tp)
{
    top[u] = tp; pos[u] = ++id;
    num[id] = u;
    if (~son[u]) dfs1(son[u], tp);
    for (int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == fa[u] || v == son[u]) continue;
        dfs1(v, v);
    }
}
/*---------以上为剖分-------------*/
int getSum(int u, int v) // 两点之间路径上的和等
{
    int f1 = top[u], f2 = top[v];
    int ans = 0;
    while (f1 != f2)
    {
        if (dep[f1] < dep[f2])
        {
            swap(u, v);
            swap(f1, f2);
        }
        ans += Query(pos[f1], pos[u], 1);
        u = fa[f1], f1 = top[u];
    }
    if (dep[u] > dep[v]) swap(u, v);
    ans += Query(pos[u], pos[v], 1);
    return ans;
}
void Change(int u, int v, int c)//更新两点之间的值等
{
    int f1 = top[u], f2 = top[v];
    while (f1 != f2)
    {
        if (dep[f1] < dep[f2])
        {
            swap(u, v);
            swap(f1, f2);
        }
        Update(pos[f1], pos[u], c, 1);
        u = fa[f1], f1 = top[u];//爬到另一条链
    }
    if (dep[u] > dep[v]) swap(u, v);
    Update(pos[u], pos[v], c, 1);
}