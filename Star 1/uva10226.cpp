// accept
# include <iostream>
# include <string>
# include <map>
# include <iomanip>
using namespace std;
int main()
{
    int n;
    cin >> n;
    getchar(); // read newline
    getchar(); // read empty line
    bool flag = false;
    while(n--)
    {
        map<string, int> mp;
        string s;
        int sum =0;
        while(getline(cin, s) && s!="")
        {
            mp[s] ++;
            sum ++;
        }

        if (flag)
            cout << endl;

        for(auto i: mp)
        {
            cout << i.first << " " 
                 << fixed << setprecision(4) << i.second/double(sum) * 100.0 
                 << endl;
        }
        flag = true;
    }
    return 0;
}