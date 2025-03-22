// accepted
# include <iostream>
# include <cmath>
using namespace std;
/*
規律1. 奇數的完全平方數(1,9,25,...) 會落在 (根號N, 1)
規律2. 奇數的完全平方數(4,16,36,...) 會落在 (1, 根號N)
規律3. 
如果 根號N 是奇數: 會往上1步,往右 sqrt(N)步, 往下 sqrt(N)步
如果 根號N 是偶數: 會往右1步,往上 sqrt(N)步, 往左 sqrt(N)步
*/
int main()
{
    int N;
    while(cin >> N && N)
    {
        int n = sqrt(N+0.0); // 算出根號N
        int square = n*n; // 算出n^2
        if (N == square)
        {
            if (n%2) // odd
            {
                cout << 1 << " " << n << endl;
                continue;
            }
            else // even
            {
                cout << n << " " << 1 << endl;
                continue;
            }
        }

        int x=1,y=n+1;
        if (n%2) // odd: 上右下 step:(1,n,n)
        {
            if (square+1 == N) // 上
                cout << x << " " << y <<endl;
            else if (square+1+n >=N) // 右
            {
                int diff = N - (square+1);
                cout << x+diff << " " << y <<endl;
            }
            else // 左
            {
                int diff = N - (square+1+n);
                cout << x+n << " " << y-diff << endl;
            }
        }
        else // even 右上左 step:(1,n,n)
        {
            x = n+1; y=1;
            if (square+1 == N) // 右 
                cout << x << " " << y <<endl;
            else if (square+1+n >=N) // 上
            {
                int diff = N - (square+1);
                cout << x << " " << y+diff <<endl;
            }
            else
            {
                int diff = N - (square+1+n); // 左
                cout << x-diff << " " << y+n << endl;
            }
        }

    }
    return 0;
}