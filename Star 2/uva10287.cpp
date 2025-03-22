// accepted
# include <iostream>
# include <iomanip>
# include <cmath>
using namespace std;
// 數學題
int main()
{
    double l;
    while(cin >> l)
    {
        cout << fixed << setprecision(10)
             << sqrt(3) * l /2.0 << " "
             << (2*sqrt(3) - 3) * l << " "
             << sqrt(3)*l /4.0 << " "
             << l* (-7*sqrt(3) + 6 * sqrt(7) )/10.0 << endl;
    }
    return 0;
}