// accepted
# include <iostream>
using namespace std;
// 2011 1/1  = 星期六
// 算距離星期六差幾天%7 就好
int main()
{
    int t;
    cin >> t;
    string Day[]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
    int Month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    while(t--)
    {
        int m,d, days=0;
        cin >> m >> d;
        for(int i=1;i!=m;i++)
        {
            days += Month[i];
        }
        days += (d-1);
        cout << Day[days%7] << endl;
    }
    return 0;
}