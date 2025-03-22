// accepted
# include <iostream>
# include <string>
using namespace std;
int main()
{
    string s;
    string dict = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    while(getline(cin, s))
    {
        for(int i=0;i<s.length();i++)
        {
            if (s[i] == ' ')
                cout << ' ';
            else
                cout << dict[dict.find(s[i]) - 2];
        }
        cout << endl;
    }
    return 0;
}