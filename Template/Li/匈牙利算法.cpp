// 匈牙利算法
// 复杂度O(nm)
// 求最大匹配
bool find(int u)
{
    for (int v = 1; v <= n; v++)
    {
        if (e[u][v] && !vis[v])
        {
            vis[v] = true;
            if (cy[v] == -1 || find(cy[v]))
            {
                cy[v] = u;
                cx[u] = v;  // 如果不用两个数组记录匹配 ，那么下面的函数 里面不加if判断
                return true;
            }
        }
    }
    return false;
}
int maxmatch()
{
    int ans = 0;
    memset(cx,-1,sizeof cx);
    memset(cy,-1,sizeof cy);
    for (int i = 1; i <= n; i++)
    {
        if (cx[i] == -1)
        {
            memset(vis, false, sizeof vis);
            ans += find(i);
        }
    }
    return ans;
}