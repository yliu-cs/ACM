#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 5;
const double eps = 1e-8;

struct Point {
    double X, Y;

    Point operator - (Point B) {
        return (Point){X - B.X, Y - B.Y};
    }

    double operator * (Point B) {
        return X * B.X + Y * B.Y;
    }

    double Dis(Point B) {
        return sqrt((B - *this) * (B - *this));
    }
};

int N;
double VB, VS;
Point points[maxn];
Point Origin;
Point Target;
double Book;
int Ans;

int main(int argc, char *argv[]) {
    scanf("%d%lf%lf", &N, &VB, &VS);
    Origin = (Point){0.0, 0.0};
    for (int i = 1; i <= N; ++i) {
        scanf("%lf", &points[i].X);
        points[i].Y = 0.0;
    }
    scanf("%lf%lf", &Target.X, &Target.Y);
    Book = 1e20;
    Ans = 1;
    for (int i = 2; i <= N; ++i) {
        double Cost = points[i].X / VB + Target.Dis(points[i]) / VS;
        if (fabs(Cost - Book) < eps) {
            if (Target.Dis(points[i]) < Target.Dis(points[Ans])) {
                Ans = i;
            }
        }
        else if (Cost < Book) {
            Book = Cost;
            Ans = i;
        }
    }
    printf("%d\n", Ans);
    return 0;
}

