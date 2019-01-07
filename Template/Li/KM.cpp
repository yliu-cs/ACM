// 带权二分图的权值最大的完备匹配称为最佳匹配。
// KM算法求最佳匹配
int val[N][N],lx[N],ly[N];
int linky[N];
int pre[N];
bool vis[N],visx[N],visy[N];
int slack[N];
int n;
void bfs(int k)
{
    int px, py = 0,yy = 0, d;
    memset(pre, 0, sizeof(pre));
    memset(slack, INF, sizeof(slack));
    linky[py]=k;
    do{
        px = linky[py],d = INF, vis[py] = 1;
        for(int i = 1; i <= n; i++)
            if(!vis[i])
            {
                if(slack[i] > lx[px] + ly[i] - val[px][i])
                    slack[i] = lx[px] + ly[i] -val[px][i], pre[i]=py;
                if(slack[i]<d) d=slack[i],yy=i;
            }
        for(int i = 0; i <= n; i++)
            if(vis[i]) lx[linky[i]] -= d, ly[i] += d;
            else slack[i] -= d;
        py = yy;
    }while(linky[py]);
    while(py) linky[py] = linky[pre[py]] , py=pre[py];
}
int KM()
{
    memset(lx, 0, sizeof(lx));
    memset(ly, 0, sizeof(ly));
    memset(linky, 0, sizeof(linky));
    for(int i = 1; i <= n; i++)
        memset(vis, false, sizeof(vis)), bfs(i);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    ans += lx[i] + ly[i];
    return ans;
}