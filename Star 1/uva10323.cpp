// accepted
# include <iostream>
using namespace std;
# define lower 10000
# define upper 6227020800
long long int  fib[10010] = {1,1}; // 能存夠正常的範圍就好
int main()
{
    int max = -1 ,min = -1;
    for(int i=2;i<10010;i++)
    {
        fib[i] = i* (i-1) *fib[i-2];
        if (max==-1 && fib[i] > upper)
            max = i;
        if (min == -1 && fib[i] > lower)
            min = i-1;
    }
    
    int n;
    while(cin >> n)
    {
        if (n < 0) // 擴展fib的定義而得
        {
            if (n%2) // 無限大
                cout << "Overflow!" << endl;
            else // 負無限大
                cout << "Underflow!" << endl;
            continue;
        }
        
        if (n >= max)
            cout << "Overflow!" << endl;
        else if (n <= min)
            cout << "Underflow!" << endl;
        else
            cout << fib[n] << endl;
    }
    return 0;
}