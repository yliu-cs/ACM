#include<bits/stdc++.h>
using namespace std;

struct Dot {
    long long Y1, Y2;
};

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N;
    cin >> N;
    long long X1, X2;
    cin >> X1 >> X2;
    vector<Dot> dots;
    for (long long i = 1, K, B; i <= N; ++i) {
        cin >> K >> B;
        dots.push_back((Dot){K * X1 + B, K * X2 + B});
    }
    sort(dots.begin(), dots.end(), [&](Dot Key1, Dot Key2) {
        if (Key1.Y1 == Key2.Y1) {
            return Key1.Y2 < Key2.Y2;
        }
        return Key1.Y1 < Key2.Y1;
    });
    for (int i = 1; i < (int)dots.size(); ++i) {
        if (dots[i].Y2 < dots[i - 1].Y2) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}

