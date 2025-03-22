// accepted
# include <iostream>
using namespace std;
int main()
{
    string s;
    while(getline(cin ,s))
    {
        bool flag = false;
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            // 遇到字母跟非字母的交界 就加一
            // isalpha() : 判斷是不是字母 是:回傳0
            if(isalpha(s[i]))
            {
                if (!flag)
                {
                    count++;
                    flag = true;
                }  
            }
            else
            {
                flag = false;
            }
        }
        cout << count << endl;
        s.clear();
    }
    return 0;
}