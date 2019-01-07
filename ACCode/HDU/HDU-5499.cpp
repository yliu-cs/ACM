#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct student {
    char Name[20];
    char Sex[6];
    bool Gender;
    int Round1;
    int Round2;
    double Res;
}q[100];

// 排序规则
bool cmp(student A,student B) {
    return A.Res > B.Res;
}

double flag1 = 0,flag2 = 0;
int BookFemale = 0;

// 数据读取
void Getinformation(int x) {
    for (int i = 0; i < x ; ++i) {
        cin >> q[i].Name >> q[i].Sex >> q[i].Round1 >> q[i].Round2;
        q[i].Gender = 0;
        if (q[i].Round1 > flag1) {
            flag1 = q[i].Round1;
        }
        if (q[i].Round2 > flag2) {
            flag2 = q[i].Round2;
        }
        if (q[i].Sex[0] == 'm') {
            q[i].Gender = 0;
        }
        else {
            q[i].Gender = 1;
            BookFemale++;
        }
    }
}

void CalculateRes(int x) {
    flag1 = 300 / flag1;
    flag2 = 300 / flag2;
    for (int i = 0; i < x; ++i) {
        q[i].Res = q[i].Round1 * flag1 * 0.3 + q[i].Round2 * flag2 * 0.7;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n,m;
        cin >> n >> m;
        Getinformation(n);
        CalculateRes(n);
        sort(q,q+n,cmp);
        cout << "The member list of Shandong team is as follows:" << endl;
        int Book = 0;
        for (int i = 0 ; i < m ; ++i) {
            if (q[i].Gender == 1) {
                Book++;
            }
        }
        if (BookFemale != 0 && Book == 0) {
            for (int i = 0 ; i < m - 1 ; ++i) {
                cout << q[i].Name << endl;
            }
            for (int i = 0 ; i < n ; ++i) {
                if (q[i].Gender == 1) {
                    cout << q[i].Name << endl;
                    break;
                }
            }
        }
        else {
            for (int i = 0 ; i < m ; ++i) {
                cout << q[i].Name << endl;
            }
        }
        BookFemale = 0;
    }
    return 0;
}
