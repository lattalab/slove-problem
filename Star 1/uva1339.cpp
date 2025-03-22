#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//只要每個 出現次數是一樣就好
int main()
{
    string a,b;
    while(cin>>a&&cin>>b)
    {
        if(a.length()!=b.length())
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            
        int na[26]={0},nb[26]={0};
        for(int i=0;i<a.length();i++)
        na[a[i]-65]++;

        for(int j=0;j<b.length();j++)
        nb[b[j]-65]++;

        sort(na,na+26);
        sort(nb,nb+26);
        bool flag = 1;
        for(int k=0;k<26;k++)
        {
            if(na[k]!=nb[k])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
        

        }

    }
    return 0;
}