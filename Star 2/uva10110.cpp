// accepted
# include <iostream>
# include <cmath>
using namespace std;
// 有偶數個因數就是暗，不然就是亮
// 因數成對出現
// 平方數例外 (兩數相同) => 必奇數個因數
int main()
{
    long long int n;
    while(cin >> n && n)
    {
        long long int sq = sqrt(n);
        if (sq * sq == n)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}