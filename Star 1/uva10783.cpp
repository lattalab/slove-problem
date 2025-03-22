#include <iostream>
using namespace std;
//uva 10783
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
    int T;
    cin>>T;
    int count=1;
    while(T--)
    {
        int a,b;
        cin>>a>>b;
        int sum=0;
        for(int j=min(a,b);j<=max(a,b);j++)
        {
            if(j%2==1)
            sum+=j;
        }
        cout<<"case "<<count<<": "<<sum<<endl;
        count++;
    }
    return 0;
}