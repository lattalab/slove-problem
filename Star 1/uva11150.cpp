// accepted
// 公式解: * 1.5
# include <iostream>
using namespace std;
int max(int a , int b , int c , int d)
{
    int max = a;
    if (b>max)
        max = b;
    if (c >max)
        max = c;
    if (d>max)
        max = d;
    return max;
}
int main()
{
    int n;
    while(cin >> n)
    {
        int sum[4];
        for (int i=0;i<=3;i++) // 可以借的瓶子數量
        {
            int s = n , empty = n + i;
            while(empty >= 3)
            {
                s += empty/3; // 多喝的罐數 
                empty = empty/3 + empty%3; // 下一輪會剩的總瓶數 
            }
            if (empty < i) // 不能還回去
                sum[i] =s-1;
            else
                sum[i] = s;

        }
        cout << max(sum[0],sum[1],sum[2],sum[3]) << endl;

    }
    return 0;
}