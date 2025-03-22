// accepted
# include <iostream>
using namespace std;
int main()
{
    int s;
    long long int d;
    while(cin >> s && cin >> d)
    {
        while(d > 0)
        {
            d -= s;
            s ++ ;
        }
        cout << s-1 << endl;
    }
    return 0;
}