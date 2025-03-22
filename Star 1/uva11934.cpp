// accepted
# include <iostream>
using namespace std;
int value[1005];
int main()
{
    int a,b,c,d,l;
    while(cin >> a >> b >> c >> d >> l)
    {
        if (a==0 && b==0 && c==0 && d==0 && l==0)
            break;

        for(int i=0;i<=l;i++)
            value[i] = a*i*i + b*i + c;

        int count=0;
        for(int i=0;i<=l;i++)
        {
            if (value[i]%d == 0)
                count ++;
        }

        cout << count << endl;
    }
    return 0;
}