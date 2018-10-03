#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

struct Sale {
    char Fruit[80];
    char City[80];
    int Num;
}q[100];

// 数据读取
void GetInformation(int x) {
    for (int i = 0;i < x;++i) {
        cin >> q[i].Fruit >> q[i].City >> q[i].Num;
    }
}

// 排序规则
bool cmp(Sale A,Sale B) {
    if (strcmp(A.City,B.City)) {
        return strcmp(A.City,B.City) < 0;
    }
    else {
        return strcmp(A.Fruit,B.Fruit) < 0;
    }
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        int M;
        cin >> M;
        GetInformation(M);
		// 结构体排序
        sort(q,q+M,cmp);
        char di[80],min[80];
        int cnt = 0,flag = 1;
        strcpy(di,q[0].City);
        strcpy(min,q[0].Fruit);
		// 输出信息时合并
        for (int i = 0;i < M;++i) {
            if (strcmp(di,q[i].City)) {
                strcpy(di,q[i].City);
                strcpy(min,q[i].Fruit);
                flag = 1;
                cnt = 0;
            }
            if (!strcmp(di,q[i].City)) {
                if (flag) {
                    cout << di << endl;
                    flag = 0;
                }
                if (!strcmp(min,q[i].Fruit)) {
                    while (!strcmp(min,q[i].Fruit) && !strcmp(di,q[i].City)) {
                        cnt += q[i].Num;
                        i++;
                    }
                    cout << "   |----" << min << "(" << cnt << ")" << endl;
                    strcpy(min,q[i].Fruit);
                    i--;
                    cnt = 0;
                }
            }
        }
        if (N) {
            cout << endl;
        }
    }
    return 0;
}
