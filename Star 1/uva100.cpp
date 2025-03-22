// accept
#include <iostream>
using namespace std;
//uva 100
int min(int i,int j)
{
    if(i>j)
    return j;
    else
    return i;
}
int max(int i,int j)
{
    if(i>j)
    return i;
    else
    return j;
}
int main()
{
    int i,j;
    while(cin>>i&&cin>>j)
    {
        int temp=0;
        int m=min(i,j),M=max(i,j); 
        for(int k=m;k<=M;k++)
        {
           int len_i=1; // store max_length
           int n=k;
           while(n!=1) // algorithm
            {
            if(n%2==0)
            n=n/2;
            else
            n=3*n+1;

            len_i++;
            } 

            if(len_i>temp) // record max length
            {
            temp=len_i;
            }
        }
        cout<<i <<" "<< j <<" "<< temp <<endl;
    }
    return 0;
}