#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;

struct student {
    int Num;
    string Name;
    int Grade;
}q[100050];

// 排序规则
bool cmp1(student A,student B) {
    return A.Num < B.Num;
}

bool cmp2(student A,student B) {
    if (A.Name == B.Name) {
        return A.Num < B.Num;
    }
    else {
        return A.Name < B.Name;
    }
}

bool cmp3(student A,student B) {
    if (A.Grade == B.Grade) {
        return A.Num < B.Num;
    }
    else {
        return A.Grade < B.Grade;
    }
}

int main() {
    int N,C,book = 1;
    while (cin >> N >> C,N) {
        for (int i = 0;i < N;++i) {
            cin >> q[i].Num >> q[i].Name >> q[i].Grade;
        }
		// 根据排序规则进行结构体排序
        if (C == 1) {
            sort(q,q + N,cmp1);
        }
        else if (C == 2) {
            sort(q, q + N, cmp2);
        }
        else if (C == 3) {
            sort(q, q + N, cmp3);
        }
        cout << "Case " << book++ << ":" << endl;
		// 补零输出
        for (int i = 0;i < N;++i) {
            if (q[i].Num >= 100000) {
                printf("%d ",q[i].Num);
            }
            else if (q[i].Num >= 10000) {
                printf("0%d ",q[i].Num);
            }
            else if (q[i].Num >= 1000) {
                printf("00%d ",q[i].Num);
            }
            else if (q[i].Num >= 100) {
                printf("000%d ",q[i].Num);
            }
            else if (q[i].Num >= 10) {
                printf("0000%d ",q[i].Num);
            }
            else {
                printf("00000%d ",q[i].Num);
            }
            cout << q[i].Name << " " << q[i].Grade << endl;
        }
    }
    return 0;
}
