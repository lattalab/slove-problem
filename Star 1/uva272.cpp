// accept
// note that: it's not always start at first time.
// 有可能不含成對雙引號
# include <iostream>
# include <string>
using namespace std;

int main()
{
    string s;
    bool flag = 0; // 0 for first time ", 1 for second time "
    while(getline(cin,s))
    {
        for (int i=0;i<s.length();i++)
        {
            if (s[i] == '\"')
            {
                if (!flag)
                {
                    s.replace(i,1,"``");
                    flag = 1;
                }
                else
                {
                    s.replace(i,1,"\''");
                    flag = 0;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}