// accepted
# include <iostream>
# include <string.h>
using namespace std;
int map[105][105];
int count;
void dfs(int x, int y)
{
    if (x<0 || y<0 || x>100 || y>100) // out of size range
        return;
    if (map[x][y] ==2 || map[x][y] == 0) // not lake
        return;

    map[x][y] = 2; // 標記成走過
    count ++; // 記錄湖面積
    
    // 走四個方向
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}
int main()
{
    int t;
    cin >> t;
    string s;
    getline(cin ,s); // read newline
    bool flag = false; // set output
    while(t--)
    {
        if (flag) // every output lie with empty line
            cout << endl;
            
        int i,j, row =0, len;

        cin >> i >> j;
        getline(cin ,s); // read newline

        memset(map, 0 , sizeof(map)); // reset

        while(getline(cin , s) && s != "")
        {
            len = s.length();
            for(int i=0;i<len;i++)
            {
                // let water = 1, land = 2
                map[row+1][i+1] = int(s[i]-'0') + 1;
            }
            row ++;
        }
        
        count = 0; // reset count
        dfs(i,j); // dfs search
        cout << count << endl; // output water area
        flag = true;
    }
    return 0;
}