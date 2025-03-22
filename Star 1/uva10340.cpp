// accepted
# include <iostream>
# include <string>
using namespace std;
// 題目大意: 一字串s，任意加字得到t
// 給兩字串s,t， 判斷t刪除某些字之後是否可得到s
int main()
{
    string s,t;
    while (cin >> s >> t)
    {
        int i,j;
        int slen=s.length(), tlen = t.length();
        for(i=0 ,j=0;i<slen, j<tlen;)
        {
            if (s[i] == t[j]) 
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
            
        }

        if (i == slen)
            cout << "Yes" <<endl;
        else
            cout << "No" <<endl;
    }
    
    return 0;
}