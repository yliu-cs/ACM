// Tarjan求连通分量
/*求连通分量*/
bool vis[maxn];
int dfn[maxn]; //搜索的时间戳
int low[maxn]; //树中最小子树的根，结点父亲的时间戳
int Stack[maxn];//栈
int belong[maxn];
int num[maxn]; // 各连通分量点个数 不一定需要
int id, tot, top, scc;
struct Edge
{
    int v, next;
}e[maxn*maxn];
int head[maxn];
void init()
{
    memset(head, -1, sizeof(head));
    memset(vis, false, sizeof(vis));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(num, 0, sizeof(num));
    tot = 0;
    id = 0;
    top = 0;
    scc = 0; // 连通分量数
}
void addedge(int u, int v)
{
    e[tot].v = v;
    e[tot].next = head[u];
    head[u] = tot++;
}
void tarjan(int u)
{
    int v;
    dfn[u] = low[u] = ++id;
    Stack[top++] = u;
    vis[u] = true;
    for(int i = head[u];i != -1;i = e[i].next)
    {
        v = e[i].v;
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(vis[v])
        {
           low[u] = min(low[u],dfn[v]);
        }
    }
    if(low[u] == dfn[u])
    {
        scc++;
        do
        {
            v = Stack[--top];
            vis[v] = false;
            belong[v] = scc;
            num[scc]++;
        }while(u != v);

    }
}