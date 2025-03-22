// Accepted
# include <iostream>
using namespace std;
int parent[50005];
bool merge(int x, int y, int n)
{
    if (parent[x] == parent[y]) // x, y are in the same set
        return false;

    // x, y are not in the same set
    int mimimum = min(parent[x], parent[y]);
    int maximum = max(parent[x], parent[y]);

    for(int i=1 ;i<=n ;i++)
        if(parent[i] == maximum)
            parent[i] = mimimum;
    return true;
}
int main()
{ 
    int n, m, cases = 1;
    while(cin >> n >> m && (n && m))
    {
        // initialize
        for(int i=0;i<50005;i++)
            parent[i] = i;

        int ans = n;
        while(m--)
        {
            int a, b;
            cin >> a >> b;

            bool check = merge(a, b, n);
            if (check)
                ans--; // after merge, the number of set - 1
        }
        
        cout << "Case " << cases++ << ": " << ans << endl;
    }
    return 0;
}