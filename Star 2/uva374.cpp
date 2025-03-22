// accepted
# include <iostream>
using namespace std;
int qpow(int b, int p, int m)
{
    if (p==0)
        return 1;
    if (p%2 == 1)
        return ((b%m) * (qpow(b, p-1, m)%m)) %m;
    else
    {
        int temp = qpow(b, p/2, m);
        return ((temp%m) * (temp%m))%m;
    }
}
int main()
{
    int b,p,m;
    while(cin >> b >> p >> m)
    {
        cout << qpow(b,p,m) << endl;
    }
    return 0;
}