# include <iostream>
using namespace std;
const int maxn = 33000; // 2^15 = 32 * 1024 = 32768
int Notprime[maxn] = {0};
int main()
{
    // 質數篩法
    Notprime[0] = Notprime[1] = 1;
    for(int i=2;i<maxn;i++)
    {
        if (Notprime[i] == 0)
        {
            for(int j = i+i; j<maxn; j+=i)
            {
                Notprime[j] = 1;
            }
        }
    }

    int n;
    while(cin >> n && n)
    {
        int count=0;
        // such that a+b = n , a、b belong to prime number.
        for(int i=2;i<= n/2;i++)
        {
            if ( (!(Notprime[i])) && (!(Notprime[n-i])) )
            {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}