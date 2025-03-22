// accepted
# include <iostream>
# include <vector>
# include <cmath>
using namespace std;
/* 
每個數字 都有同樣的d 跟 r
使得 An = Qn * d + r
相鄰兩項相減，可移除 r ， 找他們的最大公因數
*/ 
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x%y);
}
int main()
{
    int num;
    while(cin >> num)
    {
        vector<int> v;
        if (num == 0)
            break;
        v.push_back(num);
        while(cin >> num && num)
        {
            v.push_back(num);
        }

        // 放絕對值可保證d為正
        int ans = abs(v[1]-v[0]);
        for(int i=1; i<v.size()-1;i++)
        {
            ans = gcd(ans, abs(v[i+1]-v[i]));
        }
        cout << abs(ans) << endl;
    }
     
    return 0;
}