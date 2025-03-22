// accepted
# include <iostream>
# include <vector>
using namespace std;
int main()
{
    string s;
    char ch;
    int n;
    while(cin >> s >> ch >> n)
    {
        vector<int> q; // 商
        long long rem = 0; // 餘數 (long long 防止overflow)
        for(int i=0;i<s.length();i++) // 除法過程
        {
            rem = 10*rem + (s[i]-'0');
            q.push_back(rem/n);
            rem %= n;
        }
        // output
        if (ch == '%')
            cout << rem << endl;
        else
        {
            bool zero = true;
            for(auto i:q)
            {
                if (zero) 
                {
                    // 商前面的零不用輸出
                    zero = (i == 0);
                    if (zero)
                        continue;
                }
                cout << i;
            }
            if (zero) // 沒有商(商 = 0)
                cout << 0 << endl;
            else
                cout << endl;
        }
    }
    return 0;
}