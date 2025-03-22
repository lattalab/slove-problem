// accepted
#include <iostream>
#include <cmath>
using namespace std;
//uva 11461
int min(int a,int b)
{
    if(a>b)
    return b;
    else
    return a;
}
int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
int main()
{
    int count=0;
    int a,b;
    while(cin>>a&&cin>>b)
    {
        if(a==0&&b==0)
        break;
        for(int j=min(a,b);j<=max(a,b);j++)
        {
            int temp=sqrt(j);
            if(temp*temp==j)
            count++;
        }
        cout<<count<<endl;
        count=0;
    }
    return 0;
}