//accept

#include <iostream>
using namespace std;
int table[40]={0,1}; //store fib (fib[40] = 102334155 ,is too big)
int main()
{
    for(int i=2;i<40;i++) //initialize fib table
    {
    table[i]=table[i-1]+table[i-2];
    }
    
    int N, n, x;
    cin >> N;
    while (N--){
        cin>>n;
        cout<<n<<" = ";

        bool flag = 0;
        for(int i=39;i>=2;i--)
        {
            if(n>=table[i]) // 由後往前找即可
            {
                n-=table[i];
                flag=1;
                cout<<"1";
            }
            else if(flag)
            {
                cout<<"0";
            }
        }
        cout<<" (fib)"<<endl;
    }
    return 0;
}