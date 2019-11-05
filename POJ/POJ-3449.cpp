#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1e2 + 5;
const double eps = 1e-8;

int Sgn(double X) {
    if (fabs(X) < eps) {
        return 0;
    }
    if (X < 0) {
        return -1;
    }
    else {
        return 1;
    }
}

struct Point {
    double X, Y;

    Point() {}
    Point(double _X, double _Y) {
        X = _X;
        Y = _Y;
    }

    void Input() {
        scanf("%lf%lf", &X, &Y);
    }

    Point operator - (const Point &B) const {
        return Point(X - B.X, Y - B.Y);
    }

    double operator * (const Point &B) const {
        return X * B.X + Y * B.Y;
    }

    double operator ^ (const Point &B) const {
        return X * B.Y - Y * B.X;
    }
};

struct Segment {
    char Code;
    Point S, T;

    Segment() {}
    Segment(char _Code, Point _S, Point _T) {
        Code = _Code;
        S = _S;
        T = _T;
    }

    void Input() {
        S.Input();
        T.Input();
    }

    double operator ^ (const Segment &B) const {
        return (T - S) ^ (B.T - B.S);
    }
};

bool IsIntersect(Segment A, Segment B) {
    return
        max(A.S.X, A.T.X) >= min(B.S.X, B.T.X) &&
        max(B.S.X, B.T.X) >= min(A.S.X, A.T.X) &&
        max(A.S.Y, A.T.Y) >= min(B.S.Y, B.T.Y) &&
        max(B.S.Y, B.T.Y) >= min(A.S.Y, A.T.Y) &&
        Sgn((B.S - A.T) ^ (A.S - A.T)) * Sgn((B.T - A.T) ^ (A.S - A.T)) <= 0 &&
        Sgn((A.S - B.T) ^ (B.S - B.T)) * Sgn((A.T - B.T) ^ (B.S - B.T)) <= 0;
}

int Cnt;
Point points[maxn];
char Str[maxn];
char Code;
char Shape[maxn];
vector<Segment> Graph[maxn];
vector<char> Ans[maxn];

bool Cmp(vector<Segment> A, vector<Segment> B) {
    return A[0].Code < B[0].Code;
}

bool Input() {
    for (int i = 0; i < Cnt; ++i) {
        Graph[i].clear();
        Ans[i].clear();
    }
    Cnt = 0;
    while (true) {
        scanf("%c", &Code);
        if (Code == '-') {
            getchar();
            return true;
        }
        else if (Code == '.') {
            return false;
        }
        scanf("%s", Shape);
        if (!strcmp(Shape, "line")) {
            scanf(" (%lf,%lf) (%lf,%lf)", &points[0].X, &points[0].Y, &points[1].X, &points[1].Y);
            Graph[Cnt].push_back(Segment(Code, points[0], points[1]));
        }
        else if (!strcmp(Shape, "triangle")) {
            scanf(" (%lf,%lf) (%lf,%lf) (%lf,%lf)", &points[0].X, &points[0].Y, &points[1].X, &points[1].Y, &points[2].X, &points[2].Y);
            Graph[Cnt].push_back(Segment(Code, points[0], points[1]));
            Graph[Cnt].push_back(Segment(Code, points[2], points[1]));
            Graph[Cnt].push_back(Segment(Code, points[0], points[2]));
        }
        else if (!strcmp(Shape, "square")) {
            scanf(" (%lf,%lf) (%lf,%lf)", &points[0].X, &points[0].Y, &points[1].X, &points[1].Y);
            points[2].X = (points[0].X + points[0].Y + points[1].X - points[1].Y) / 2;
            points[2].Y = (-points[0].X + points[0].Y + points[1].X + points[1].Y) / 2;
            points[3].X = (points[0].X - points[0].Y + points[1].X + points[1].Y) / 2;
            points[3].Y = (points[0].X + points[0].Y - points[1].X + points[1].Y) / 2;
            Graph[Cnt].push_back(Segment(Code, points[0], points[2]));
            Graph[Cnt].push_back(Segment(Code, points[2], points[1]));
            Graph[Cnt].push_back(Segment(Code, points[1], points[3]));
            Graph[Cnt].push_back(Segment(Code, points[3], points[0]));
        }
        else if (!strcmp(Shape, "rectangle")) {
            scanf(" (%lf,%lf) (%lf,%lf) (%lf,%lf)", &points[0].X, &points[0].Y, &points[1].X, &points[1].Y, &points[2].X, &points[2].Y);
            points[3].X = points[0].X + points[2].X - points[1].X;
            points[3].Y = points[0].Y + points[2].Y - points[1].Y;
            Graph[Cnt].push_back(Segment(Code, points[0], points[1]));
            Graph[Cnt].push_back(Segment(Code, points[1], points[2]));
            Graph[Cnt].push_back(Segment(Code, points[2], points[3]));
            Graph[Cnt].push_back(Segment(Code, points[3], points[0]));
        }
        else if (!strcmp(Shape, "polygon")) {
            int Num;
            scanf("%d", &Num);
            for (int i = 0; i < Num; ++i) {
                scanf(" (%lf,%lf)", &points[i].X, &points[i].Y);
                if (i) {
                    Graph[Cnt].push_back(Segment(Code, points[i - 1], points[i]));
                }
            }
            Graph[Cnt].push_back(Segment(Code, points[0], points[Num - 1]));
        }
        Cnt++;
        getchar();
    }
}

void Check(int X, int Y) {
    for (int i = 0; i < int(Graph[X].size()); ++i) {
        for (int j = 0; j < int(Graph[Y].size()); ++j) {
            if (IsIntersect(Graph[X][i], Graph[Y][j])) {
                Ans[X].push_back(Graph[Y][j].Code);
                Ans[Y].push_back(Graph[X][i].Code);
                return;
            }
        }
    }
}

void Output(int X) {
    if (int(Ans[X].size()) == 0) {
        printf("%c has no intersections\n", Graph[X][0].Code);
    }
    else if (int(Ans[X].size()) == 1) {
        printf("%c intersects with %c\n", Graph[X][0].Code, Ans[X][0]);
    }
    else if (int(Ans[X].size()) == 2) {
        printf("%c intersects with %c and %c\n", Graph[X][0].Code, Ans[X][0], Ans[X][1]);
    }
    else {
        printf("%c intersects with ", Graph[X][0].Code);
        for (int i = 0; i < int(Ans[X].size()) - 1; ++i) {
            printf("%c, ", Ans[X][i]);
        }
        printf("and %c\n", Ans[X].back());
    }
}

void Solve() {
    sort(Graph, Graph + Cnt, Cmp);
    for (int i = 0; i < Cnt; ++i) {
        for (int j = i + 1; j < Cnt; ++j) {
            Check(i, j);
        }
        Output(i);
    }
}

// POJ-3449交C++

int main(int argc, char *argv[]) {
    while (Input()) {
        Solve();
        printf("\n");
    }
	return 0;
}

