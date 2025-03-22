// accepted
# include <iostream>
# include <string>
# include <cmath>
using namespace std;
// 題意: 給予一個N進制且能被N-1整除的數，那麼每個位數的總和也會被N-1整除
/* ex: N進制數字:  ab
ab = a*N^2 + b = a*(N-1+1) + b = a*(N-1) + (a+b)
已知 可被N-1整除，則 a+b也可被N-1整除 */
// 之後輸出 N進制的N
int main()
{
    string s;
    while(getline(cin,s)) // 測資為一行
    {
        int temp; // store digit
        int sum =0 , max_div=1; // 進制最少是2
        for (int i=0;i<s.length();i++)
        {
            if ('0'<=s[i] && s[i]<='9')
                temp = s[i] - '0';
            else if ('A'<=s[i] && s[i]<='Z')
                temp = s[i]-'A' +10;
            else if ('a'<=s[i] && s[i]<='z')
                temp = s[i]-'a' +36;
            else //跳過空白、正負號之類的
                continue;

            sum += temp;
            max_div = max(max_div, temp);
        }
        
        int i;
        for(i=max_div;i<62;i++)
        {
            if (sum%i == 0) // 找到 N-1
            {
                cout << i+1 << endl;
                break;
            }
        }
        if (i == 62)
            cout << "such number is impossible!" << endl;
    }
    return 0;
}