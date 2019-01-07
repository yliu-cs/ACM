#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct Milk {
    string S;
    int P;
    int V;
    double Price;
    bool Less;
}q[100];

// 数据读取
void GetInformation(int x) {
    for (int i = 0 ; i < x ; ++i) {
        cin >> q[i].S >> q[i].P >> q[i].V;
        if (q[i].V % 200 == 0 && q[i].V <= 1000 && q[i].V >= 200) {
            q[i].Price = q[i].P / (q[i].V / 200);
        }
        else if (q[i].V > 1000) {
            q[i].Price = q[i].P / 5;
        }
        else if (q[i].V < 200) {
            q[i].Price = 0;
        }
        else {
            int Change = q[i].V / 200;
            q[i].Price = q[i].P / Change;
        }
        if (q[i].V < 200) {
            q[i].Less = 0;
        }
        else {
            q[i].Less = 1;
        }
    }
}

// 排序规则
bool cmp(Milk A,Milk B) {
    if (A.Less == 1 && B.Less == 0) {
        return true;
    }
    else if (A.Less == 0 && B.Less == 1) {
        return false;
    }
    if (A.Price == B.Price) {
        return A.V > B.V;
    }
    return A.Price < B.Price;
}

int main() {
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        GetInformation(N);
		// 结构体排序
        sort(q,q + N,cmp);
        cout << q[0].S << endl;
    }
    return 0;
}
