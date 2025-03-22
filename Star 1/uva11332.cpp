// accepted
# include <iostream>
using namespace std;
int f(int n)
{
    int sum=0;
    while(n)
    {
        sum+=n%10;
        n/=10;
    }
    if(sum>=10)
    return f(sum);
    else
    return sum;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
        break;
        cout<<f(n)<<endl;
    }
    return 0;
}