#include <bits/stdc++.h>
using namespace std;

typedef double db;
const int maxn = 1e1 + 5;
const db eps = 1e-6;

int Sgn(db Key) {return fabs(Key) < eps ? 0 : (Key < 0 ? -1 : 1);}
int Cmp(db Key1, db Key2) {return Sgn(Key1 - Key2);}
struct Point {db X, Y;};
typedef Point Vector;
Vector operator - (Vector Key1, Vector Key2) {return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y};}
Vector operator + (Vector Key1, Vector Key2) {return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y};}
db operator * (Vector Key1, Vector Key2) {return Key1.X * Key2.X + Key1.Y * Key2.Y;}
db operator ^ (Vector Key1, Vector Key2) {return Key1.X * Key2.Y - Key1.Y * Key2.X;}
db DisPointToPoint(Point Key1, Point Key2) {return sqrt((Key2 - Key1) * (Key2 - Key1));}
struct Line {Point S, T;};
typedef Line Segment;
bool IsSegInterSeg(Segment Key1, Segment Key2) {
    return
        max(Key1.S.X, Key1.T.X) > min(Key2.S.X, Key2.T.X) &&
        max(Key2.S.X, Key2.T.X) > min(Key1.S.X, Key1.T.X) &&
        max(Key1.S.Y, Key1.T.Y) > min(Key2.S.Y, Key2.T.Y) &&
        max(Key2.S.Y, Key2.T.Y) > min(Key1.S.Y, Key1.T.Y) &&
        Sgn((Key2.S - Key1.T) ^ (Key1.S - Key1.T)) * Sgn((Key2.T - Key1.T) ^ (Key1.S - Key1.T)) < 0 &&
        Sgn((Key1.S - Key2.T) ^ (Key2.S - Key2.T)) * Sgn((Key1.T - Key2.T) ^ (Key2.S - Key2.T)) < 0;
}
bool IsConvexHull(vector<pair<Point, int>> Key) {
    int N = (int)Key.size();
    int Low = 0;
    for (int i = 0; i < N; ++i)
        if (Sgn((Key[(i + 1) % N].first - Key[i].first) ^ (Key[(i + 2) % N].first - Key[(i + 1) % N].first)) < 0)
            return false;
    return true;
}

pair<Point, int> points[maxn];
bool Vis[maxn];
bool Flag;
vector<pair<Point, int>> Square;
vector<pair<Point, int>> Rectangle;
vector<pair<Point, int>> SquareTemp;
vector<pair<Point, int>> RectangleTemp;

bool Check() {
    SquareTemp.assign(Square.begin(), Square.end());
    RectangleTemp.assign(Rectangle.begin(), Rectangle.end());
    int Low = 0;
    for (int i = 0; i < SquareTemp.size(); ++i)
        if (Cmp(SquareTemp[i].first.X, SquareTemp[Low].first.X) < 0 || (Cmp(SquareTemp[i].first.X, SquareTemp[Low].first.X) == 0 && (Cmp(SquareTemp[i].first.Y, SquareTemp[Low].first.Y) < 0))) Low = i;
    swap(SquareTemp[0], SquareTemp[Low]);
    sort(SquareTemp.begin() + 1, SquareTemp.end(), [&](pair<Point, int> Key1, pair<Point, int> Key2) {
        db Temp = (Key1.first - SquareTemp[0].first) ^ (Key2.first - SquareTemp[0].first);
        if (Sgn(Temp) > 0) return true;
        else if (Sgn(Temp) == 0 && Cmp(DisPointToPoint(Key2.first, SquareTemp[0].first), DisPointToPoint(Key1.first, SquareTemp[0].first)) > 0) return true;
        return false;
    });
    Low = 0;
    for (int i = 0; i < RectangleTemp.size(); ++i)
        if (Cmp(RectangleTemp[i].first.X, RectangleTemp[Low].first.X) < 0 || (Cmp(RectangleTemp[i].first.X, RectangleTemp[Low].first.X) == 0 && (Cmp(RectangleTemp[i].first.Y, RectangleTemp[Low].first.Y) < 0))) Low = i;
    swap(RectangleTemp[0], RectangleTemp[Low]);
    sort(RectangleTemp.begin() + 1, RectangleTemp.end(), [&](pair<Point, int> Key1, pair<Point, int> Key2) {
        db Temp = (Key1.first - RectangleTemp[0].first) ^ (Key2.first - RectangleTemp[0].first);
        if (Sgn(Temp) > 0) return true;
        else if (Sgn(Temp) == 0 && Cmp(DisPointToPoint(Key2.first, RectangleTemp[0].first), DisPointToPoint(Key1.first, RectangleTemp[0].first)) > 0) return true;
        return false;
    });
    if (!IsConvexHull(SquareTemp) || !IsConvexHull(RectangleTemp)) return false;
    if (SquareTemp.size() != 4 || RectangleTemp.size() != 4) return false;
    if (!IsSegInterSeg((Segment){SquareTemp[0].first, SquareTemp[2].first}, (Segment){SquareTemp[1].first, SquareTemp[3].first}) || Cmp(DisPointToPoint(SquareTemp[0].first, SquareTemp[2].first), DisPointToPoint(SquareTemp[1].first, SquareTemp[3].first)) != 0 || Cmp(DisPointToPoint(SquareTemp[0].first, SquareTemp[1].first), DisPointToPoint(SquareTemp[0].first, SquareTemp[3].first)) != 0) return false;
    if (!IsSegInterSeg((Segment){RectangleTemp[0].first, RectangleTemp[2].first}, (Segment){RectangleTemp[1].first, RectangleTemp[3].first}) || Cmp(DisPointToPoint(RectangleTemp[0].first, RectangleTemp[2].first), DisPointToPoint(RectangleTemp[1].first, RectangleTemp[3].first)) != 0) return false;
    return true;
}

void Dfs(int Pos, int Cnt) {
    if (Cnt == 4) {
        Rectangle.clear();
        for (int i = 0; i < 8; ++i)
            if (!Vis[i])
                Rectangle.push_back(points[i]);
        if (Check()) Flag = true;
        return;
    }
    if (Pos == 8) return;
    Square.push_back(points[Pos]);
    Vis[Pos] = true;
    Dfs(Pos + 1, Cnt + 1);
    if (Flag) return;
    Square.pop_back();
    Vis[Pos] = false;
    Dfs(Pos + 1, Cnt);
    if (Flag) return;
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < 8; ++i) {
        scanf("%lf%lf", &points[i].first.X, &points[i].first.Y);
        points[i].second = i + 1;
    }
    Flag = false;
    memset(Vis, false, sizeof(Vis));
    Dfs(0, 0);
    sort(Square.begin(), Square.end(), [&](pair<Point, int> Key1, pair<Point, int> Key2) {return Key1.second < Key2.second;});
    sort(Square.begin(), Square.end(), [&](pair<Point, int> Key1, pair<Point, int> Key2) {return Key1.second < Key2.second;});
    if (Flag) {
        printf("YES\n");
        for (auto &it : Square) printf("%d ", it.second);
        printf("\n");
        for (auto &it : Rectangle) printf("%d ", it.second);
        printf("\n");
    }
    else printf("NO\n");
    return 0;
}
