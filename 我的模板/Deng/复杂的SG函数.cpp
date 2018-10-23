/*
复杂的SG函数 Hdu-3797
题意：
    有n个容量为s的盒子，每个盒子里原有的石子有ci个，问谁能赢
思路：
    每个盒子中的s 和c 之间存在的输赢关系是一定的，把每个盒子的SG值先异或可以得最终这个游戏得SG值，根据SG来判断输赢
    比如：一个盒子得s = 20
如果 c=20, 那么先手必败 SG[20] = 0;
如果c= 19 SG【19】得后继为SG【20】，即SG【19 】 = 1
如果c = 18 SG【18】得后继为SG【19】，SG【20】，即SG【18】 = 2
.......
如果c = 4 SG【4】得后继有。。。，SG【4】得后继为SG【4】= 16
当c = 3是c不能经过一步操作到达20，所以他的后继中无SG【20】，所以最小值为0，所以SG【3】 = 0；
同理 SG【2】 = 1；
SG【1】 = 0；
SG【0】 = 0；
SG【】的后继就是他在他能一步到达的SG中已存在的数，从0开始不存在的数
比如4能到达SG[5]--SG[20],而SG[5]--SG[20]包含的数从0->15，所以SG[4]=16,而SG[3]只能到达SG[4]-SG[12]，而没有SG[20]=0，所以SG[3] = 0
从4后可以看成一个循环，3和20都是必输点，而后面的0也是必输点
当一个人处在必胜点的时候，他可以通过操作来是到达离他最近的一个必输点，那么他就是必胜得，同理，当一个人先手处于必输点得时候，那么他就是必输的
*/
#include<iostream>
#include<math.h>
using namespace std;
int getsg(int s, int c) {
    int t = sqrt(s);
    while (t * t + t >= s) t --;
    if (c > t) return s - c;
    else return getsg(t, c);
}
int main() {
    int n;
    int cnt = 0;
    while(cin >> n && n) {
        cnt ++;
        int t = 0;
        while(n--) {
            int s, c;
            cin >> s >> c;
            t ^= getsg(s, c);
        }
        cout << "Case "<<cnt<< ":"<< endl;
        if (t) {
            cout << "Yes"<<endl;
        }else{
            cout << "No"<<endl;
        }
    }
    return 0;
}