// accepted
# include <iostream>
# include <cmath>
using namespace std;
bool isprime(int num)
{
    for(int i=2;i<sqrt(num)+1;i++)
    {
        if (num%i == 0)
            return false;
    }
    return true;
}
int reverse(int num)
{
    int r =0;
    while(num)
    {
        r += num%10;
        num /=10;
        r *= 10;
    }
    r /= 10;
    return r;
}
int main()
{
    int n;
    while(cin >> n)
    {
        bool prime = isprime(n);
        int r = reverse(n);
        bool emirp = isprime(r);
        if (!prime)
            cout << n << " is not prime.\n";
        else if (prime && emirp && n!=r)
            cout << n << " is emirp.\n";
        else
            cout << n << " is prime.\n";
    }
    return 0;
}