// accepted
# include <iostream>
# include <vector>
using namespace std;
int main()
{
    long long int n,m;
    while(cin >> n && cin >>m)
    {
        vector<long long int> v;
        bool div = false;
        v.push_back(n);
        if (n== 0 || n==1|| m == 0 || m==1)
            cout << "Boring!\n";
        while(n!=1 && n>1 && m>1)
        {
            if (n%m) // 不整除
            {
                cout << "Boring!\n";
                div = false;
                break;
            }
            n/=m;
            v.push_back(n);
            div =true;
        }
        if (div)
        {
            cout << v[0];
            for(int i=1;i<v.size();i++)
            {
                cout << " " << v[i];
            }
            cout <<endl;
        }
        
    }
    return 0;
}