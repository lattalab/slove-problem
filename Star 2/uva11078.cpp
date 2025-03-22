// accepted
# include <iostream>
# include <vector>
# include <cmath>
using namespace std;
int main()
{
    int t, n , num;
    cin >> t;
    while(t--)
    {
        cin >> n; // number of people
        vector<int> v;
        for(int i=0;i<n;i++) // score
        {
            cin >> num;
            v.emplace_back(num);
        }

        // it satisfy the increasing order and decreasin order
        int senior = v[0], diff = v[0]-v[1];
        for(int i=1;i<v.size();i++)
        {
            diff = max(diff, senior - v[i]);
            senior = max(senior, v[i]);
        }
        cout << diff << endl;
    }
    return 0;
}