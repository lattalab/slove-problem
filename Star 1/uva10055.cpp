// accepted
# include <iostream>
# include <cmath>
using namespace std;
int main()
{
    long long int a,b; // long long int is 8 bytes(64 bits)
    while(cin>>a && cin >>b)
    {
        cout << abs(a-b) << endl;
    }
    return 0;
}