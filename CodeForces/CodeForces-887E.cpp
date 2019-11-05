#include <bits/stdc++.h>
using namespace std;
typedef double db;
const db inf = 1e13;
const db eps = 1e-9;

int Sgn(db k) {return fabs(k) < eps ? 0 : (k < 0 ? -1 : 1);}
int Cmp(db k1, db k2) {return Sgn(k1 - k2);}
struct Point {db x, y;};
typedef Point Vector;
Vector operator - (Vector k1, Vector k2) {return (Vector){k1.x - k2.x, k1.y - k2.y};}
Vector operator + (Vector k1, Vector k2) {return (Vector){k1.x + k2.x, k1.y + k2.y};}
db operator * (Vector k1, Vector k2) {return k1.x * k2.x + k1.y * k2.y;}
db operator ^ (Vector k1, Vector k2) {return k1.x * k2.y - k1.y * k2.x;}
Vector operator * (Vector k1, db k2) {return (Vector){k1.x * k2, k1.y * k2};}
Vector operator / (Vector k1, db k2) {return (Vector){k1.x / k2, k1.y / k2};}
db GetLen(Vector k) {return sqrt(k * k);}
db GetDisPointToPoint(Point k1, Point k2) {return sqrt((k2 - k1) * (k2 - k1));}
Vector Rotate(Vector k, db ang) {return (Vector){k.x * cos(ang) - k.y * sin(ang), k.x * sin(ang) + k.y * cos(ang)};}
Vector Rotate90(Vector k) {return (Vector){-k.y, k.x};}
struct Circle {Point o; db r;};
bool IsInside(Circle k1, Circle k2) {
    db dis = GetDisPointToPoint(k1.o, k2.o);
    if (Cmp(k1.r - k2.r, dis) >= 0 || Cmp(k2.r - k1.r, dis) >= 0) return true;
    return false;
}
bool IsOutside(Circle k1, Circle k2) {
    db dis = GetDisPointToPoint(k1.o, k2.o);
    if (Cmp(dis, k1.r + k2.r) > 0) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cout << fixed << setprecision(10);

    Point s, t;
    cin >> s.x >> s.y >> t.x >> t.y;
    int n; cin >> n;
    vector<Circle> c(n);
    for (auto &it : c) cin >> it.o.x >> it.o.y >> it.r;

    Point mid_point = (s + t) / 2.0;
    Vector dir = Rotate90(t - s) / GetLen(t - s);
    db dis_div2 = GetDisPointToPoint(s, mid_point);

    bool ans_flag = true;
    for (auto &it : c) {
        Circle cur = (Circle){mid_point, dis_div2};
        if (!IsInside(cur, it) && !IsOutside(cur, it)) {
            ans_flag = false;
            break;
        }
    }
    if (ans_flag) {
        cout << dis_div2 << endl;
        return 0;
    }

    vector<pair<db, db>> record;
    for (auto &it : c) {
        bool dir_flag;
        if (Sgn((it.o - mid_point) * dir) > 0) dir_flag = true;
        else dir_flag = false;
        db inside_record, outside_record; Circle binary_search_cur;

        int binary_search_cnt = 0;
        db binary_search_left = -inf, binary_search_right = inf;
        while (Cmp(binary_search_left, binary_search_right) && binary_search_cnt++ < 100) {
            db binary_search_mid = (binary_search_left + binary_search_right) / 2.0;
            binary_search_cur.o = dir * binary_search_mid + mid_point;
            binary_search_cur.r = sqrt(binary_search_mid * binary_search_mid + dis_div2 * dis_div2);
            if (IsInside(binary_search_cur, it)) {
                inside_record = binary_search_mid;
                if (dir_flag) binary_search_right = binary_search_mid;
                else binary_search_left = binary_search_mid;
            }
            else {
                if (dir_flag) binary_search_left = binary_search_mid;
                else binary_search_right = binary_search_mid;
            }
        }

        binary_search_cnt = 0;
        binary_search_left = -inf, binary_search_right = inf;
        while (Cmp(binary_search_left, binary_search_right) && binary_search_cnt++ < 100) {
            db binary_search_mid = (binary_search_left + binary_search_right) / 2.0;
            binary_search_cur.o = dir * binary_search_mid + mid_point;
            binary_search_cur.r = sqrt(binary_search_mid * binary_search_mid + dis_div2 * dis_div2);
            if (IsOutside(binary_search_cur, it)) {
                outside_record = binary_search_mid;
                if (dir_flag) binary_search_left = binary_search_mid;
                else binary_search_right = binary_search_mid;
            }
            else {
                if (dir_flag) binary_search_right = binary_search_mid;
                else binary_search_left = binary_search_mid;
            }
        }

        if (Cmp(inside_record, outside_record) > 0) swap(inside_record, outside_record);
        record.push_back(make_pair(inside_record, outside_record));
    }

    sort(record.begin(), record.end(), [&](pair<db, db> k1, pair<db, db> k2) {return Cmp(k1.first, k2.first) < 0;});
    db ans = Cmp(-record[0].first, 0.0) > 0 ? -record[0].first : 0.0;
    db fi = record[0].first, se = record[0].second;
    for (int i = 1; i < record.size(); ++i) {
        if (Cmp(se, record[i].first) < 0) {
            if (Cmp(ans, fabs(se)) > 0) ans = fabs(se);
            if (Cmp(ans, fabs(record[i].first)) > 0) ans = fabs(record[i].first);
            fi = record[i].first;
        }
        if (Cmp(record[i].second, se) > 0) se = record[i].second;
    }
    if (Cmp(ans, fabs(se)) > 0) ans = fabs(se);

    cout << sqrt(ans * ans + dis_div2 * dis_div2) << endl;
    return 0;
}

