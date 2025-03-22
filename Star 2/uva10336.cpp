// accepted
# include <iostream>
# include <map>
# include <algorithm>
# include <vector>
using namespace std;
// 陣列這樣居然夠大!
char arr[1000][1000]={0};
bool visited[1000][1000]={0}; // to record whether walk or not
void dfs(int x, int y, char ch , int h , int w)
{
    // 超出範圍 跟 走過 不繼續
    if (x<0 || x>=h || y<0 || y >= w || visited[x][y]) 
        return ;
    else if (arr[x][y] != ch) // 字母不一樣 不繼續
        return;
    else
        visited[x][y] = true; // 記錄已走過

    dfs(x,y+1,ch,h,w);
    dfs(x,y-1,ch,h,w);
    dfs(x-1,y,ch,h,w);
    dfs(x+1,y,ch,h,w);
}
bool cmp(pair<char,int> &a, pair<char,int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;

    return a.second > b.second;
}
int main()
{
    int n; // test cases
    int world = 1;
    cin >> n;
    while(n--)
    {
        int h,w;
        cin >> h >> w;

        for(int i=0;i<h;i++) // input map
        {
            for(int j=0;j<w;j++)
            {
                cin >> arr[i][j];
                visited[i][j] = false;
            }
        }

        map<char, int> mp;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if (!visited[i][j])
                {
                    dfs(i,j,arr[i][j],h,w); // find the state
                    mp[arr[i][j]] ++; // calculate how many state.
                }
            }
        }

        cout << "World #" << world++ << endl; // start output
        vector<pair<char,int>> v; // sort according to the question
        for(auto i:mp)
            v.push_back({i.first,i.second});

        sort(v.begin(),v.end(),cmp);
        for(auto i:v)
            cout << i.first << ": " << i.second <<endl;
    }
    return 0;
}