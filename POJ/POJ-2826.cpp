#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const double eps = 1e-8;

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
    Point S, T;

    Segment() {}
    Segment(Point _S, Point _T) {
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

bool IsIntersect(Segment A, Segment B){
    return 
        max(A.S.X, A.T.X) >= min(B.S.X, B.T.X) &&
        max(B.S.X, B.T.X) >= min(A.S.X, A.T.X) &&
        max(A.S.Y, A.T.Y) >= min(B.S.Y, B.T.Y) &&
        max(B.S.Y, B.T.Y) >= min(A.S.Y, A.T.Y) &&
        (A ^ Segment(A.S, B.S)) * (A ^ Segment(A.S, B.T)) < eps &&
        (B ^ Segment(B.S, A.S)) * (B ^ Segment(B.S, A.T)) < eps;
}

Point IntersectionPoint(Segment A, Segment B) {
    double X = (B.T - B.S) ^ (A.S - B.S), Y = (B.T - B.S) ^ (A.T - B.S);
    return Point((A.S.X * Y - A.T.X * X) / (Y - X), (A.S.Y * Y - A.T.Y * X) / (Y - X));
}

// POJ 2826 此题要交C++,G++会Wrong Answer

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        Segment O, P;
        O.Input();
        P.Input();
        if (O.S.Y == O.T.Y || P.S.Y == P.T.Y) {
            printf("0.00\n");
        }
        else if (IsIntersect(O, P)) {
            Point CrossPoint = IntersectionPoint(O, P);
            Point TopPoint[2];
            int Flag = 0;
            if (O.S.Y > CrossPoint.Y) {
                TopPoint[Flag++] = O.S;
            }
            if (O.T.Y > CrossPoint.Y) {
                TopPoint[Flag++] = O.T;
            }
            if (P.S.Y > CrossPoint.Y) {
                TopPoint[Flag++] = P.S;
            }
            if (P.T.Y > CrossPoint.Y) {
                TopPoint[Flag++] = P.T;
            }
            if (Flag < 2) {
                printf("0.00\n");
                continue;
            }
            if (TopPoint[1].Y < TopPoint[0].Y) {
                swap(TopPoint[0], TopPoint[1]);
            }
            if (IsIntersect(Segment(CrossPoint, TopPoint[1]), Segment(TopPoint[0], Point(TopPoint[0].X, TopPoint[0].Y + 10005)))) {
                printf("0.00\n");
                continue;
            }
            TopPoint[1] = IntersectionPoint(Segment(CrossPoint, TopPoint[1]), Segment(Point(TopPoint[0].X - 2, TopPoint[0].Y), TopPoint[0]));
            double Ans = fabs(((TopPoint[1] - CrossPoint) ^ (TopPoint[0] - CrossPoint))) / 2;
            printf("%.2lf\n", Ans + eps);
        }
        else {
            printf("0.00\n");
        }
    }
	return 0;
}

