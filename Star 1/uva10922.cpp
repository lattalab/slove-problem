// accepted
# include <iostream>
# include <string>
using namespace std;
// 題意: 判斷這個數的總和是不是9的倍數，直到剩一位數
int multipler(string &s, int count)
{
    int sum=0;
    if (s == "9") // 如果傳9進來
        return count+1;

    for(int i=0;i<s.length();i++)
    {
        sum += (s[i]-'0');
    }

    if (sum%9 == 0)
    {
        int c = count +1;
        if (sum == 9)
            return c;

        string str = to_string(sum);
        int ans = multipler(str,c);
        return ans;
    }

    return count;
}
int main()
{
    string n;
    while(cin >> n && n!="0")
    {
        
        int count = multipler(n,0);
        
        if(count)
            cout << n << " is a multiple of 9 and has 9-degree " << count <<".\n";
        else
            cout << n << " is not a multiple of 9.\n";

        n.clear();
    }
    return 0;
}