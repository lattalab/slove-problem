// accepted
#include <bits/stdc++.h> //萬用檔
using namespace std;
/*
建質數表，從2開始試，試到根號n，看能不能整除
如果全部跑完最後不等於一，那剩下來的那個數字一定是質數
*/
# define Size 1005
bool Notprime[Size]; // 質數表
vector<int> v;
int main()
{
    for(int i=0;i<Size;i++)
        Notprime[i] = false;
    
    for(int i=2;i<Size;i++)
    {
        if (!Notprime[i])
            v.push_back(i); // 存質數
        for(int j=i*i;j<Size;j+=i)
            Notprime[j] = true;
    }

    int n;
    while(cin >> n && n)
    {
        int count =0, temp=n;

        for(int i=0;i<v.size();i++)
        {
            if (v[i] > n) break; // 停止條件

            if (temp%v[i] == 0)
            {
                count ++;
                while(temp%v[i] == 0) // 一直除質數 (類似質因數分解的過程)
                    temp /= v[i];
            }
        }
        if (temp > 1) count++; // 如果大於1, 那個數會是質數

        cout << n << " : " << count <<endl;
    }
    return 0;
}