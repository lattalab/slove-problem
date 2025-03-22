// accepted
# include <iostream>
using namespace std;
string s;
void dfs(int idx, string t)
{
    if (idx == s.length())
    {
        cout << t << endl;
        return;
    }
    for(int j=0;j<=t.length();j++)
    {
        t.insert(j, string{s[idx]}); // insert : 在特定某位置插入字元
        dfs(idx+1, t);
        t.erase(j , 1); // erase : 在某位置移除n個字元
    }
}
int main()
{
    bool flag = false;
    while(getline(cin ,s ))
    {
        if (flag)
            cout << endl;
        dfs(0, "");
        flag = true;
    }
    return 0;
}