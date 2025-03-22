// accepted
# include <iostream>
# include <cmath>
using namespace std;
int main()
{
    string s;
    while(cin >> s && s != "0")
    {
        int odd=0, even=0;
        for(int i=0;i<s.length();i+=2)
        {
            odd += s[i] - '0';
        }
        for(int i=1;i<s.length();i+=2)
        {
            even += s[i] - '0';
        }
        int diff = abs(odd-even); 
        if (diff%11 == 0) // 該數的奇數和跟偶數和的差為11的倍數就是 11的倍數
            cout << s << " is a multiple of 11.\n";
        else
            cout << s << " is not a multiple of 11.\n";
    }
    return 0;
}