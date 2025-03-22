// accepted
# include <iostream>
using namespace std;
int main()
{
    int n,k;
    while(cin >> n >> k)
    {
        int sum =n, temp=n;
        while (temp >= k)
        {
            sum += (temp/k);
            temp = (temp/k) + (temp%k);
        }
        cout << sum <<endl;
    }
    return 0;
}