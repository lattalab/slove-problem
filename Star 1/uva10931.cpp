// accepted
#include <iostream>
using namespace std;
void bin(int n)
{
    int binary[32]={0},count=0,i=0,num=0;
    while(n) // 反過來算二進位
    {
        binary[i++]=n%2;
        n/=2;
        count++; // 記錄二進位的尾巴到哪
    }
    for(int j=count-1;j>=0;j--)
    {
        cout<<binary[j];
        if(binary[j]==1)
        num++; // 紀錄有幾個1
    }
    cout<<" is "<<num<<" (mod 2)."<<endl;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
        break;
        cout<<"The parity of ";
        bin(n);
    }
    return 0;
}