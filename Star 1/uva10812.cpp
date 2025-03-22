// accepted
# include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        long long int sum,diff;
        cin >> sum >> diff;
        long long int a = (sum+diff)/2, b= sum-a;
        if (a<0 || b<0)
            cout << "impossible\n";
        else if ((sum+diff)%2) // 加起來為奇數不合理
            cout << "impossible\n";
        else
            cout << a << " " << b << endl;
    }
    return 0;
}