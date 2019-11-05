#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 5e2 + 5;

struct Node {int V, Len, Time;};

int N, M;
vector<Node> G[maxn];
int S, T;

int TDis[maxn];
int Dur[maxn];
bool TVis[maxn];
int TPath[maxn];

void MinTime() {
    memset(TDis, INF, sizeof(TDis));
    memset(Dur, INF, sizeof(Dur));
    memset(TVis, false, sizeof(TVis));
    memset(TPath, -1, sizeof(TPath));
    Dur[S] = 0; TDis[S] = 0;
    for (int i = 0; i < N; ++i) {
        int U = -1, Min = INF;
        for (int i = 0; i < N; ++i) {
            if (TVis[i]) continue;
            if (Dur[i] < Min) {
                U = i;
                Min = Dur[i];
            }
            else if (Dur[i] == Min && TDis[i] < TDis[U]) {
                U = i;
            }
        }
        if (U == -1) return;
        if (U == T) return;
        TVis[U] = true;
        for (auto &it : G[U]) {
            if (TVis[it.V]) continue;
            if (Dur[U] + it.Time < Dur[it.V]) {
                Dur[it.V] = Dur[U] + it.Time;
                TDis[it.V] = TDis[U] + it.Len;
                TPath[it.V] = U;
            }
            else if (Dur[U] + it.Time == Dur[it.V] && TDis[U] + it.Len < TDis[it.V]) {
                TDis[it.V] = TDis[U] + it.Len;
                TPath[it.V] = U;
            }
        }
    }
}

vector<int> TPathAns;

void FindTPath(int Cur) {
    if (TPath[Cur] != -1) FindTPath(TPath[Cur]);
    TPathAns.push_back(Cur);
}

int Dis[maxn];
int Cnt[maxn];
bool Vis[maxn];
int Path[maxn];

void MinLen() {
    memset(Dis, INF, sizeof(Dis));
    memset(Cnt, INF, sizeof(Cnt));
    memset(Vis, false, sizeof(Vis));
    memset(Path, -1, sizeof(Path));
    Dis[S] = 0; Cnt[S] = 1;
    for (int i = 0; i < N; ++i) {
        int U = -1, Min = INF;
        for (int i = 0; i < N; ++i) {
            if (Vis[i]) continue;
            if (Dis[i] < Min) {
                U = i;
                Min = Dis[i];
            }
            else if (Dis[i] == Min && Cnt[i] < Cnt[U]) {
                U = i;
            }
        }
        if (U == -1) continue;
        if (U == T) continue;
        Vis[U] = true;
        for (auto &it : G[U]) {
            if (Vis[it.V]) continue;
            if (Dis[U] + it.Len < Dis[it.V]) {
                Dis[it.V] = Dis[U] + it.Len;
                Cnt[it.V] = Cnt[U] + 1;
                Path[it.V] = U;
            }
            else if (Dis[U] + it.Len < Dis[it.V] && Cnt[U] + 1 < Cnt[it.V]) {
                Cnt[it.V] = Cnt[U] + 1;
                Path[it.V] = U;
            }
        }
    }
}

vector<int> PathAns;

void FindPath(int Cur) {
    if (Path[Cur] != -1) FindPath(Path[Cur]);
    PathAns.push_back(Cur);
}

int main(int argc, char *argv[]) {
    cin >> N >> M;
    for (int i = 0, U, V, Flag, Len, Time; i < M; ++i) {
        cin >> U >> V >> Flag >> Len >> Time;
        G[U].push_back((Node){V, Len, Time});
        if (!Flag) G[V].push_back((Node){U, Len, Time});
    }
    cin >> S >> T;
    MinTime();
    FindTPath(T);
    MinLen();
    FindPath(T);
    if (TPathAns == PathAns) {
        cout << "Time = " << Dur[T] << ";" << " Distance = " << Dis[T] << ": " << PathAns[0];
        for (int i = 1; i < PathAns.size(); ++i) cout << " => " << PathAns[i];
        return 0;
    }
    cout << "Time = " << Dur[T] << ": " << TPathAns[0];
    for (int i = 1; i < TPathAns.size(); ++i) cout << " => " << TPathAns[i];
    cout << endl;
    cout << "Distance = " << Dis[T] << ": " << PathAns[0];
    for (int i = 1; i < PathAns.size(); ++i) cout << " => " << PathAns[i];
    return 0;
}

