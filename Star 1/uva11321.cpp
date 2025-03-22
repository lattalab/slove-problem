// accepted
# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
using namespace std;
bool cmp(pair<int,int> &a, pair<int,int> &b)
{
    if (a.first == b.first)
    {
        // 負數%2 = -1， 所以正負數判斷是否奇數加個abs
        if (abs(a.second %2)==1 && abs(b.second %2) == 0) // 一奇一偶
            return 1;
        else if (a.second%2 ==0 && abs(b.second %2) == 1) 
            return 0;
        else if (abs(a.second%2) == 1 && abs(b.second%2) == 1) // 兩個奇數
            return a.second > b.second;
        else // 兩個偶數
            return a.second < b.second;
    }
    return  a.first < b.first;
}
int main()
{
    int n,m;
    while(cin >> n >> m )
    {
        if (n == 0 && m ==0)
        {
            cout << "0 0\n";
            break;
        }
        cout << n << " " << m << endl;
        vector<pair<int, int>> v;
        int num;
        for(int i=0;i<n;i++)
        {
            cin >> num;
            v.push_back(pair<int,int>(num%m, num));
        }
        sort(v.begin(), v.end(), cmp);

        for(int i=0;i<v.size();i++)
            cout << v[i].second << endl;
    }
    return 0;
}