// accepted
# include <iostream>
# include <string>
using namespace std;
long long int fact[1001][2600] = {{1},{1}};
int main()
{
    // 先計算完所有階層結果
    // PS: 大數乘法
    // n! = (n-1)! * n
    for(int i=2;i<1001;i++) 
    {
        for(int j=0;j<2600;j++) // 每位數*i
        {
            fact[i][j] = fact[i-1][j] * i;
        }

        // 反過來表示
        // ex: 120 -> 0 2 1
        for(int j=0;j<2600;j++)
        {
            if (fact[i][j] >= 10) // 乘法進法
            {
                fact[i][j+1] += (fact[i][j]/10);
                fact[i][j] %= 10;
            }
        }
    }

    int n;
    while(cin >> n)
    {
        int sum =0;
        for(int i=0;i<2600;i++) // 每位數相加
        {
            sum += fact[n][i];
        }
        cout << sum << endl;
    }
    return 0;
}