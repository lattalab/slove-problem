// accepted
# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
using namespace std;
int main()
{
    int n;

    while(cin >> n)
    {
        int num;
        vector<int> v;
        vector<int> dis;

        for (int i=0;i<n; i++) // enter all number
        {
            cin >> num;
            v.push_back(num);
        }

        for(int i=0;i<v.size()-1;i++) // calculate abs()
        {
            dis.push_back(abs(v[i+1]-v[i]));
        }
        sort(dis.begin(), dis.end()); // sort ascending

        bool flag =0;
        for(int i=0;i<dis.size();i++) // 差值1~n-1都要有，其餘不可存在
        {
            if(dis[i] != i+1 || dis[i] >= n)
            {
                flag = 1;
                break;
            }
        }
        
        if(flag)
            cout << "Not jolly" <<endl;
        else
            cout << "Jolly" <<endl;
    }
    return 0;
}