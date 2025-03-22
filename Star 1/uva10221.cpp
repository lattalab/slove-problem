// accepted
# include <iostream>
# include <string>
# include <cmath>
# include <iomanip>
using namespace std;
# define pi acos(-1)
# define r 6440.0
int main()
{
    double s,a;
    double chord, arc;
    string str;
    while(cin >> s >> a >> str)
    {
        if (str.compare("min") == 0) // equal
        {
            a /= 60;   // 轉換成角度
        }
        while(a >360)
        {
            a -= 360;
        }
        if (a > 180) // 
        {
            a = 360 - a;
        }    
        chord = 2*(s+r)*sin(a/2.0/180.0 * pi);
        arc = 2*pi*(s+r) * a/360.0;
        cout <<fixed << setprecision(6) << arc << " " << chord << endl;
    }
    return 0;
}