// accepted
# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
using namespace std;
int main()
{
    int testcase;
    cin >> testcase;

    while(testcase--)
    {
        int n; // number of neighbor
        cin >> n;
        int s, mid, total =0;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            cin >> s; // neighbor's door number
            v.push_back(s);
        }

        sort(v.begin(),v.end());

        // 所有絕對值相加最小值，發生在 數值 中位數
        // ex: |x-a|+|x-b|+|x-c| -> (a+b+c)/3 最小
        // find median
        mid = v[n/2]; // 這樣算起來會一樣

        for(int i=0;i<v.size();i++)
        {
            total += abs(v[i] - mid);
        }
        cout << total <<endl;
    }
    return 0;
}