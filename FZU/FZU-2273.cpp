#include <cstdio>
#include <cmath>
using namespace std;

const double eps = 1e-8;

struct Point {
    double X, Y;
    Point(double _X = 0, double _Y = 0): X(_X), Y(_Y) {}
    void Input() {
        scanf("%lf%lf", &X, &Y);
    }
    Point operator - (const Point &b) const {
        return Point (X - b.X, Y - b.Y);
    }
    double operator ^ (const Point &b) const {
        return X * b.Y - Y * b.X;
    }
    bool operator == (const Point &b) const {
        return fabs(X - b.X) < eps && fabs(Y - b.Y) < eps;
    }
};

struct Segment {
    Point P, Q;
    void Input() {
        P.Input(); Q.Input();
    }
    double operator ^ (const Segment &b) const {
        return (Q - P) ^ (b.Q - b.P);
    }
};

bool IntersectJudge(Segment A, Segment B) {
    Segment Temp1, Temp2, Temp3, Temp4;
    Temp1.P = A.P; Temp1.Q = B.P;
    Temp2.P = A.P; Temp2.Q = B.Q;
    Temp3.P = B.P; Temp3.Q = A.P;
    Temp4.P = B.P; Temp4.Q = A.Q;
    if ((A ^ Temp1) * (A ^ Temp2) <= 0 && (B ^ Temp3) * (B ^ Temp4) <= 0) {
        return true;
    }
    return false;
}

bool ContainJudge(Segment A, Segment B, Point C) {
    Point Vertex;
    if (A.P == B.P || A.P == B.Q) {
        Vertex = A.P;
        if (A.P == B.Q) {
            Point Temp = B.P;
            B.P = B.Q;
            B.Q = Temp;
        }
    }
    else if (A.Q == B.P || A.Q == B.Q) {
        Vertex = A.Q;
        if (A.Q == B.P) {
            Point Temp = B.Q;
            B.Q = B.P;
            B.P = Temp;
        }
    }
    Segment Judge;
    Judge.P = Vertex; Judge.Q = C;
    if ((A ^ Judge) * (B ^ Judge) <= 0) {
        return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        Segment Temp;
        int nx[3] = {0, 0, 1}, ny[3] = {1, 2, 2};
        Segment TriangleA[3], TriangleB[3];
        Point Vertex[6];
        for (int i = 0; i < 6; ++i) {
            Vertex[i].Input();
        }
        for (int i = 0; i < 3; ++i) {
            TriangleA[i].P = Vertex[nx[i]]; TriangleA[i].Q = Vertex[ny[i]];
        }
        for (int i = 0; i < 3; ++i) {
            TriangleB[i].P = Vertex[nx[i] + 3]; TriangleB[i].Q = Vertex[ny[i] + 3];
        }
        bool IntersectFlag = false;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (IntersectJudge(TriangleA[i], TriangleB[j])) {
                    IntersectFlag = true;
                }
            }
        }
        bool ContainFlag = true;;
        for (int i = 0; i < 3; ++i) {
            for (int j = 3; j < 6; ++j) {
                if (!ContainJudge(TriangleA[nx[i]], TriangleA[ny[i]], Vertex[j])) {
                    ContainFlag = false;
                }
            }
        }
        if (ContainFlag) {
            printf("contain\n");
            continue;
        }
        ContainFlag = true;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (!ContainJudge(TriangleB[nx[i]], TriangleB[ny[i]], Vertex[j])) {
                    ContainFlag = false;
                }
            }
        }
        if (ContainFlag) {
            printf("contain\n");
            continue;
        }
        if (IntersectFlag) {
            printf("intersect\n");
            continue;
        }
        printf("disjoint\n");
    }
    return 0;
}

