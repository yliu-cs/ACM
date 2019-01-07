#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

// 威佐夫博弈。
/*
 * 通过公式判断是否可胜
 * 由于题目数据范围不大则可直接暴力枚举判断第一步取子情况
 */

int main(){
    //fre();
    int a, b;
    while (~scanf("%d%d", &a, &b), a, b) {
        int k = b - a;
        int judge = (int)((k * (1 + sqrt(5.0))) / 2.0);
        if (judge == a) {
            printf("0\n");
        }
        else {
            printf("1\n");
            int TempA, TempB, TempK, TempJudge;
            int AnsA = -1, AnsB = -1;
            bool flag = 0;
            for (int i = 1; i <= a; ++i) {
                TempA = a - i, TempB = b - i;
                TempK = TempB - TempA;
                TempJudge = (int)((TempK * (1 + sqrt(5.0))) / 2.0);
                if (TempJudge == TempA && !flag) {
                    printf("%d %d\n", TempA, TempB);
                    flag = 1;
                }
                TempK = b - TempA;
                TempJudge = (int)((TempK * (1 + sqrt(5.0))) / 2.0);
                if (TempJudge == TempA && AnsA == -1 && AnsB == -1) {
                    AnsA = TempA;
                    AnsB = b;
                    //printf("AnsA = %d AnsB = %d\n", AnsA, AnsB);
                }
            }
            if (AnsA == -1 && AnsB == -1) {
                for (int i = 1; i <= b; ++i) {
                    TempB = b - i;
                    TempK = abs(TempB - a);
                    TempJudge = (int)((TempK * (1 + sqrt(5.0))) / 2.0);
                    if (TempJudge == a || TempJudge == TempB) {
                        AnsA = min(a, TempB);
                        AnsB = max(a, TempB);
                        //printf("AnsA = %d AnsB = %d\n", AnsA, AnsB);
                        break;
                    }
                }
            }
            if (AnsA != -1 && AnsB != -1) {
                printf("%d %d\n", AnsA, AnsB);
                //printf("AnsA = %d AnsB = %d\n", AnsA, AnsB);
            }
        }
    }
    return 0;
}
