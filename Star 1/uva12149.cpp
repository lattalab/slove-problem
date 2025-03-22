// accepted
# include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >> n && n)
    {
        int sum =0 ;
        for(int i=1;i<=n;i++)
            sum += i*i;

        // 公式: n*(n+1)*(2n+1)/6
        cout << sum << endl;
    }
    return 0;
}