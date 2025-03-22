// accepted
# include <iostream>
# include <cmath>
# include <iomanip>
using namespace std;
int main()
{
    int s;
    cin >> s;
    while(s--)
    {
        int n,target;
        double prob;
        cin >> n >> prob >> target;

        if (prob == double(0.0))
        {
            cout <<fixed << setprecision(4) << 0.000 << endl;
            continue;
        }   

        double a1 = pow(1-prob, target-1) * prob; // 首項
        double r = pow(1-prob,n); //公比
        double result = a1/(1-r);

        cout <<fixed << setprecision(4) << result << endl;
    }
    return 0;
}