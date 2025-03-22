// accepted
# include <iostream>
# include <map>
# include <vector>
using namespace std;
int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        // note: map可以對應到一個vector
        map<int, vector<int>> mp; // 該數字對應一個儲存出現位置的vector
        for(int i=0;i<n;i++)
        {
            int num;
            cin >> num;
            mp[num].push_back(i+1);
        }

        for(int i=0;i<m;i++)
        {
            int k,v;
            cin >> k >> v;
            if (mp[v].size() < k) // out of range
            {
                cout << 0 << endl;
                continue;
            }
            cout << mp[v][k-1] <<endl; // kth of v
        }
    }
    return 0;
}