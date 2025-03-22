// accepted
# include <iostream>
using namespace std;
# define ll long long int 
// extend euclidean

// call by reference -> 類似 call by pointer
// x1 = y2
// y1 = x2 - (a/b)*y2
void extend_euc(ll a , ll b , ll &x , ll &y ,ll &d)
{
    if(b==0)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        extend_euc(b, a%b , y ,x , d);
        y -= x * (a/b);
    }
}
int main()
{
    ll a,b , x, y ,d;
    while(cin >> a >> b)
    {
        extend_euc(a,b,x,y,d);
        cout << x << " " << y << " " << d << endl;
    }
    return 0;
}