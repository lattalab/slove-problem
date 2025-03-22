// accepted
# include <iostream>
# include <algorithm>
using namespace std;
int a[5];
bool dfs(int idx, int res)
{
    if (idx==4)
    {
        return res == 23;
    }

    if (dfs(idx+1, res+a[idx+1])) return true;
    else if (dfs(idx+1, res-a[idx+1])) return true;
    else if (dfs(idx+1, res*a[idx+1])) return true;
    
    return false;
}
int main()
{
    while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4])
    {
        if (!a[0]&& !a[1] && !a[2] && !a[3] && !a[4])
            break;

        sort(a,a+5);
        bool poss;
        do
        {
            poss = dfs(0,a[0]);
            if (poss)
                break;
        }
        while(next_permutation(a,a+5));

        if (poss)
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
    }
    return 0;
}