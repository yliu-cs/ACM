#include <iostream>
#include <iomanip>
using namespace std;
// 直接计算
int main()
{
    cout << "n e" << endl;
    cout << "- -----------" << endl;
    cout << 0 << " " << 1 << endl;
    for (int j = 1;j <= 9;++j)
    {
        cout << j << " ";
        double res = 2;
        for (double i = 2;i <= j;++i)
        {
            double res1 = 1;
            for (double k = 1;k <= i;++k)
            {
                res1 *= k;
            }
            res += 1.0/res1;
        }
        if (j <= 2)
        {
            cout << res << endl;
        }else
        {
            cout << setiosflags(ios::fixed) << setprecision(9) << res << endl;
        }
    }
    return 0;
}
