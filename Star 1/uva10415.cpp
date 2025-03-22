// accepted
# include <iostream>
# include <string>
# include <map>
# include <vector>
using namespace std;
int main()
{
    map <char, vector<int> > mp;
    mp['c'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1};
    mp['d'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0};
    mp['e'] = {0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0};
    mp['f'] = {0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0};
    mp['g'] = {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    mp['a'] = {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    mp['b'] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    mp['C'] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
    mp['D'] = {0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0};
    mp['E'] = {0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0};
    mp['F'] = {0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0};
    mp['G'] = {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    mp['A'] = {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    mp['B'] = {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    int n;
    cin >> n;
    getchar(); // read new line
    while (n--)
    {
        string s;
        getline(cin,s);
        int count[11] ={0}; // 紀錄總共每根手指總共按了幾次
        bool last[11] ={false}; // 紀錄上次有沒有在按
        for(int i=0;i<s.length();i++)
        {
            for(int j=1;j<11;j++)
            {
                if (!last[j] && mp[s[i]][j]) // 上次沒按過&&這次要按
                {
                    count[j]++;
                    last[j] = true;
                }
                else if (!mp[s[i]][j]) // 沒有持續按了
                    last[j] = false;
            }
        }

        for(int k=1;k<10;k++) // output
            cout << count[k] << " ";

        cout << count[10] << endl;
    }
    
    return 0;
}