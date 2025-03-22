// accepted
# include <iostream>
# include <cmath>
# include <iomanip>
# include <algorithm>
using namespace std;
// note: 單位換算, 算錢問題
double money[1005];
int main()
{
    int n;
    while(cin >> n && n)
    {
        int sum =0;
        for(int i=0;i<n;i++)
        {
            cin >> money[i];
            sum += (money[i]*100.0); // 變成以cent為單位做累加
        }    

        int rem = (int)sum % n; // 有人需多付, 相對的 有人需要少付的數量
        int avg = sum/n; // 平均
        sort(money,money+n, greater<double>()); // 以大到小排序
        
        double ans = 0.0;
        for(int i=0;i<rem;i++) // 讓較大的付較少錢
            ans += abs((money[i]*100) - (avg+1));
        for(int j = rem; j<n; j++) // 讓較小的靠近平均
            ans += abs((money[j]*100) - avg);

        // 算出每個人要動的錢數, 要除以兩百 (重複算了兩次)
        cout << "$" << fixed << setprecision(2) 
             << ans/200.0 << endl;
    }
    return 0;
}