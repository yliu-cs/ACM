// Tarjan求割点&桥
/*
*求 无向图的割点和桥
*可以找出割点和桥，求删掉每个点后增加的连通块。
*/
bool vis[maxn];
int dfn[maxn]; //搜索的时间戳
int low[maxn]; //树中最小子树的根，结点父亲的时间戳
int num[maxn]; // 各连通分量点个数 不一定需要
int id, tot, top;
int bridge;
int add_block[maxn];//删除一个点后增加的连通块
struct Edge
{
    int v, next;
    bool cut; // 是否为桥(割边)
}e[maxm];
bool cut[maxn];
int head[maxn];
void init()
{
    memset(head, -1, sizeof(head));
    memset(vis, false, sizeof(vis));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(cut, false, sizeof(cut));
    tot = 0;
    id = 0;
    top = 0;
    bridge = 0;
}
void addedge(int u, int v)
{
    e[tot].v = v;
    e[tot].next = head[u];
    e[tot].cut = false;
    head[u] = tot++;
}
void tarjan(int u,int pre)
{
    int v;
    low[u] = dfn[u] = ++id;
    vis[u] = true;
    int son = 0;
    for(int i = head[u];i != -1;i = e[i].next)
    {
        v = e[i].v;
        if(v == pre)continue;
        if( !dfn[v] )
        {
            son++;
            tarjan(v,u);
            if(low[u] > low[v])low[u] = low[v];
             //桥
            //一条无向边(u,v)是桥，当且仅当(u,v)为树枝边，且满足DFS(u)<low(v)。
            if(low[v] > dfn[u])
            {
                bridge++;
                e[i].cut = true;
                e[i^1].cut = true;
            }
             //割点
            //一个顶点u是割点，当且仅当满足(1)或(2) (1) u为树根，且u有多于一个子树。
            //(2) u不为树根，且满足存在(u,v)为树枝边(或称父子边，
            //即u为v在搜索树中的父亲)，使得DFS(u)<=low(v)
            if(u != pre && low[v] >= dfn[u])//不是树根
            {
                cut[u] = true;
                add_block[u]++;
            }
        }
        else if( low[u] > dfn[v])
             low[u] = dfn[v];
    }
    if(u == pre && son > 1)cut[u] = true;
    if(u == pre)add_block[u] = son - 1;
    vis[u] = false;
}