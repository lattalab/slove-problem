// accepted
#include <iostream>
#include <cmath>
using namespace std;
//uva 11417
int table[501][501]={0}; //�H�Ŷ������ɶ�
int GCD(int i,int j)
{
    int divsor=1;
    if(i>j)
    {
        for(int k=2;k<=j;k++)
        {
            if(i%k==0&&j%k==0)
            divsor=k;
        }
    }
    else{
        for(int k=2;k<=i;k++)
        {
            if(j%k==0&&i%k==0)
            divsor=k;
        }
    }
    return divsor;
}
int main()
{
    int N;
    while(cin>>N)
    {
        if(N==0)
        break;
        int G=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=i+1;j<=N;j++)
            {
                if(table[i][j])
                G+=table[i][j];
                else
                {
                table[i][j]=GCD(i,j);
                G+=table[i][j];
                }
            }
        }
        cout<<G<<endl;
    }
    return 0;
}