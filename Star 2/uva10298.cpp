// accepted
# include <iostream>
# include <string>
using namespace std;
int kmp(string s , int slen)
{
    int next[slen+1];
    next[0] =0;
    int prev=0 ,i =1;
    while(i < slen)
    {
        if (s[i] == s[prev])
        {
            next[i] = prev+1;
            prev++;
            i++;
        }
        else if (prev == 0)
        {
            next[i] =0;
            i++;
        }
        else
        {
            prev = next[prev-1];
        }
    }

    return slen-next[slen-1];
}
int main()
{
    string s;
    while(cin >> s && s!=".")
    {
        int len = s.length();
        int num = kmp(s, len);
        if (len % num == 0)
        {
            cout << len/num <<endl;
        }   
        else
            cout << 1 << endl; 
    
    }
    return 0;
}