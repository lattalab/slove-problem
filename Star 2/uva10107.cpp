// accepted
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main()
{
    int num;
    vector<int> v;
    while(cin >> num)
    {
        v.emplace_back(num);
        sort(v.begin(),v.end()); // ascending order
        if (v.size() == 1) // only 1 element
            cout << v[0] << endl;
        else
        {
            int size = v.size();
            if (size %2) // odd
                cout << v[size/2] <<endl;
            else // even
                cout << (v[size/2] + v[size/2-1])/2 << endl;
        }
    }
    return 0;
}