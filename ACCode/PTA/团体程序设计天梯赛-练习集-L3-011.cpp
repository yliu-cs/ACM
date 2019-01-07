#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 3e2;
const double eps = 1e-5;
const double e = 2.718281828459;

struct connect {
    int v;
    int dis;
};

int n, m;
int cnt = 0;
// 每个城镇驻守的敌军数量
int people[maxn];
// 距离
int dis[maxn];
bool vis[maxn];
// 记录杀敌数量情况
int kill[maxn];
// 记录路线前驱节点
int path[maxn];
// 路线中解放城镇数量
int city[maxn];
// 到达每个城镇路径条数
int line_num[maxn];
// 邻接表
vector<connect> Adj[maxn];
// 城镇名称和编号对应关系
map<string, int> cor;
map<int, string> uncor;

void Dijkstra() {
    mem(dis, INF);
    mem(vis, 0);
    mem(path, 0);
    mem(city, 0);
    mem(kill, 0);
    mem(line_num, 0);
    // 0是己方大本营，从0开始最短路搜索
    dis[0] = 0;
    kill[0] = people[0];
    city[0] = 1;
    line_num[0] = 1;
    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && (u == -1 || dis[j] < dis[u] || (dis[j] == dis[u] && city[j] > city[u]) || (dis[j] == dis[u] && city[j] == city[u] && kill[j] > kill[u]))) {
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = 1;
        for (int j = 0; j < Adj[u].size(); ++j) {
            int v = Adj[u][j].v;
            // 选择最短路径
            if (!vis[v] && dis[u] + Adj[u][j].dis < dis[v]) {
                dis[v] = dis[u] + Adj[u][j].dis;
                kill[v] = kill[u] + people[v];
                city[v] = city[u] + 1;
                path[v] = u;
                line_num[v] = line_num[u];
            }
            // 当最短路径不唯一时选择可以沿途解放最多城镇的路径
            else if (dis[v] == dis[u] + Adj[u][j].dis && city[v] < city[u] + 1) {
                dis[v] = dis[u] + Adj[u][j].dis;
                city[v] = city[u] + 1;
                kill[v] = kill[u] + people[v];
                path[v] = u;
                line_num[v] += line_num[u];
            }
            // 当最短路径和可以沿途解放最多城镇的路径不唯一时选择可以有效杀伤最多敌军的路径
            else if (dis[v] == dis[u] + Adj[u][j].dis && city[v] == city[u] + 1 && kill[v] < kill[u] + people[v]) {
                dis[v] = dis[u] + Adj[u][j].dis;
                city[v] = city[u] + 1;
                kill[v] = kill[u] + people[v];
                path[v] = u;
                line_num[v] += line_num[u];
            }
            // 当最短路径不唯一时记录路径条数
            else if (dis[v] == dis[u] + Adj[u][j].dis) {
                line_num[v] += line_num[u];
            }
        }
    }
}

// 递归通过记录的前驱节点寻找路线并输出
void find_line(int find_line_temp) {
    if (find_line_temp == 0) {
        cout << uncor[find_line_temp];
    }
    else {
        find_line(path[find_line_temp]);
        cout << "->" << uncor[find_line_temp];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    string start_road, end_road;
    cin >> start_road >> end_road;
    cor[start_road] = cnt++;
    uncor[cnt - 1] = start_road;
    cor[end_road] = cnt++;
    uncor[cnt - 1] = end_road;
    // 记录城镇名称且与相应编号对应并记录驻守的敌军数量
    for (int i = 0; i < n - 1; ++i) {
        string name;
        int num_peo;
        cin >> name >> num_peo;
        if (!cor[name]) {
            cor[name] = cnt++;
            uncor[cnt - 1] = name;
        }
        people[cor[name]] = num_peo;
    }
    // 邻接表信息输入
    while (m--) {
        string input_u, input_v;
        int distance;
        cin >> input_u >> input_v >> distance;
        connect add;
        add.v = cor[input_v];
        add.dis = distance;
        Adj[cor[input_u]].push_back(add);
        add.v = cor[input_u];
        Adj[cor[input_v]].push_back(add);
    }
    Dijkstra();
    find_line(1);
    cout << endl;
    cout << line_num[1] << " " << dis[1] << " " << kill[1];
    return 0;
}

