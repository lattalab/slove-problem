// accepted
# include <iostream>
# include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0); cout.tie(0);
    int n;
    cin >> n; // test case
    string s;
    getline(cin , s); // read newline

    while(n--)
    {
        getline(cin , s);
        int sum =0 , num;
        bool flag = true;
        for(int i=0;i<s.length();i++)
        {
            if (s[i] == ' ')
                continue;

            if (flag)
            {
                num = (s[i] - '0')*2;
                sum += num/10 + num%10;
            }    
            else
            {
                sum += (s[i] - '0');
            }    
            flag = !flag;
        }
        if (sum%10)
            cout << "Invalid\n";
        else
            cout << "Valid\n";

        s.clear();
    }
    
    return 0;
}