// accepted
# include <iostream>
# include <cstring>
using namespace std;
int n, m ,mod;
struct matrix
{
    long long  a[2][2];
    matrix() // zero matrix
    {
        memset(a, 0 , sizeof(a));
    }
    matrix operator * (const matrix &b) const // matrix multiply
    {
        matrix ret;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    ret.a[i][j] = (ret.a[i][j] + a[i][k] * b.a[k][j]) % mod;
                }
            }
        }
        return ret;
    }
};

void solve(int k)
{
    mod = 1<<m;
    matrix ret; // identity matrix
    ret.a[0][0] = 1;
    ret.a[1][1] = 1;
    matrix main; // fib matrix
    main.a[0][0] = main.a[0][1] = main.a[1][0] = 1;
    main.a[1][1] = 0;
    while(k)
    {
        if (k & 1)
            ret = ret * main;
        k >>= 1;
        main = main * main;
    }
    cout << ret.a[0][0] << endl;
}

int main()
{
    while(cin >> n >> m)
    {
        if (n == 0 || m == 0)
            cout << "0" << endl;
        else
            solve(n-1);
    }
    return 0;
}