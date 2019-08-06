#include <bits/stdc++.h>
using namespace std;

typedef long double db;

const db eps = 1e-8;
int Sgn(db Key) {
    if (fabs(Key) < eps) return 0;
    return Key < 0 ? -1 : 1;
}
struct Point {db X, Y;};
typedef Point Vector;
bool operator == (Point Key1, Point Key2) {return Sgn(Key1.X - Key2.X) == 0 && Sgn(Key1.Y - Key2.Y) == 0;}
Vector operator + (Vector Key1, Vector Key2) {return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y};}
Vector operator - (Vector Key1, Vector Key2) {return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y};}
db operator * (Vector Key1, Vector Key2) {return Key1.X * Key2.X + Key1.Y * Key2.Y;}
db operator ^ (Vector Key1, Vector Key2) {return Key1.X * Key2.Y - Key1.Y * Key2.X;}
Vector operator * (Vector Key1, db Key2) {return (Vector){Key1.X * Key2, Key1.Y * Key2};}
Vector operator / (Vector Key1, db Key2) {return (Vector){Key1.X / Key2, Key1.Y / Key2};}
Point Rotate(Point Key, db Angle) {
    return (Point){Key.X * cos(Angle) - Key.Y * sin(Angle),
                   Key.X * sin(Angle) + Key.Y * cos(Angle)};
}
db DisPointToPoint(Point Key1, Point Key2) {return sqrt((Key1 - Key2) * (Key1 - Key2));}
db GetAngle(Vector Key1, Vector Key2) {return fabs(atan2(Key1 ^ Key2, Key1 * Key2));}
struct PolarPoint {db Angle, Length;};
Point PolarPointToPoint(PolarPoint Key) {
    return (Point){Key.Length * cos(Key.Angle),
                   Key.Length * sin(Key.Angle)};
}
struct Line {Point S, T;};
typedef Line Segment;
db Length(Segment Key) {return DisPointToPoint(Key.S, Key.T);}
db DisPointToLine(Point Key1, Line Key2) {return fabs((Key1 - Key2.S) ^ (Key2.T - Key2.S)) / Length(Key2);}
db DisPointToSegment(Point Key1, Segment Key2) {
    if (Sgn((Key1 - Key2.S) * (Key2.T - Key2.S)) < 0 || Sgn((Key1 - Key2.T) * (Key2.S - Key2.T)) < 0) {
        return min(DisPointToPoint(Key1, Key2.S), DisPointToPoint(Key1, Key2.T));
    }
    return DisPointToLine(Key1, Key2);
}
struct Circle {Point Center;db Radius;};

int T;
Point Start, End;
Circle Park;
db DisOS, DisOE;
db Angle;
db Ans;

int main(int argc, char *argv[]) {
    scanf("%d",&T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%Lf%Lf", &Start.X, &Start.Y);
        scanf("%Lf%Lf", &End.X, &End.Y);
        scanf("%Lf%Lf%Lf", &Park.Center.X, &Park.Center.Y, &Park.Radius);
        Ans = 0.0;
        if (Sgn(DisPointToSegment(Park.Center, (Segment){Start, End}) - Park.Radius) >= 0) {
            if (Sgn(DisPointToPoint(Park.Center, Start) - Park.Radius) == 0 ||
                Sgn(DisPointToPoint(Park.Center, End) - Park.Radius) == 0) {
                printf("%.3Lf\n", DisPointToPoint(Start, End));
                continue;
            }
            Angle = GetAngle((Vector){Start - Park.Center}, (Vector){End - Park.Center});
            if (Sgn(Angle) == 0) {
                printf("%.3Lf\n", DisPointToPoint(Start, Park.Center) + DisPointToPoint(End, Park.Center) - 2 * Park.Radius);
                continue;
            }
            Start = Start - Park.Center; End = End - Park.Center;
            Park.Center = Park.Center - Park.Center;
            if (Sgn(Start ^ End) < 0) swap(Start, End);
            db Left = 0.0, Right = Angle; int Cnt = 0;
            while (true) {
                db MidAngle = (Left + Right) / 2.0;
                Point MidPoint = Rotate(Start, MidAngle) * (Park.Radius / DisPointToPoint(Start, Park.Center));
                if (Sgn(GetAngle(MidPoint - Park.Center, Start - MidPoint) - GetAngle(MidPoint - Park.Center, End - MidPoint)) == 0) {
                    printf("%.3Lf\n", DisPointToPoint(Start, MidPoint) + DisPointToPoint(End, MidPoint));
                    break;
                }
                else if (Sgn(GetAngle(MidPoint - Park.Center, Start - MidPoint) - GetAngle(MidPoint - Park.Center, End - MidPoint)) > 0) Right = MidAngle;
                else Left = MidAngle;
            }
        }
        else {
            DisOS = DisPointToPoint(Park.Center, Start);
            DisOE = DisPointToPoint(Park.Center, End);
            db Temp1 = Park.Radius / DisOS, Temp2 = Park.Radius / DisOE;
            db Angle = GetAngle(Start - Park.Center, End - Park.Center);
            if (Sgn(Temp1 - 1.0) < 0) Angle -= acos(Temp1);
            if (Sgn(Temp2 - 1.0) < 0) Angle -= acos(Temp2);
            if (Sgn(DisOS - Park.Radius) > 0) Ans += sqrt(DisOS * DisOS - Park.Radius * Park.Radius);
            if (Sgn(DisOE - Park.Radius) > 0) Ans += sqrt(DisOE * DisOE - Park.Radius * Park.Radius);
            Ans += Angle * Park.Radius;
            printf("%.3Lf\n", Ans);
        }
    }
    return 0;
}
