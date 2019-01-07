// HK算法求最大匹配
// 复杂度O(mn^0.5)
// 若存双向边则匹配数*2
int dx[N], dy[N], mx[N], my[N],dis,uN;//dx, dy 表示长度,mx,my表示匹配
bool vis[N];
bool searchp()
{
    queue<int> q;
    dis = INF;
    memset(dx, -1, sizeof dx);
    memset(dy, -1, sizeof dy);
    for (int i = 1; i <= uN; i++)
    {
        if (mx[i] == -1)
        {
            q.push(i);
            dx[i] = 0;
        }
    }
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        if (dx[u] > dis) break;
        for (int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].v;
            {
                if (dy[v] == -1)
                {
                    dy[v] = dx[u] + 1;
                    if (my[v] == -1) dis = dy[v];
                    else
                    {
                        dx[my[v]] = dy[v] + 1;
                        q.push(my[v]);
                    }
                }
            }
        }
    }
    return dis != INF;
}
bool dfs(int u)
{
    for (int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;
        if (vis[v] || (dy[v] != dx[u] + 1)) continue;
        vis[v] = 1;
        if (my[v] != - 1 && dy[v] == dis) continue;
        if (my[v] == -1 || dfs(my[v]))
        {
            my[v] = u;
            mx[u] = v;
            return true;
        }
    }
    return false;
}
int HK()
{
    int res = 0;
    memset(mx, -1, sizeof mx);
    memset(my, -1, sizeof my);
    while (searchp())
    {
        memset(vis, false, sizeof vis);
        for (int i = 1; i <= uN; i++)
            if (mx[i] == -1 && dfs(i))
                res++;
    }
    return res;
}