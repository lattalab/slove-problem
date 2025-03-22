// accepted
# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;
int main()
{
    string s;
    vector<string> v;
    // 輸入有多行 -> 分好幾個getline
    while(getline(cin,s) && s != "0")
    {
        s += "\n"; // 換行也納入，不然會錯
        string temp = "";
        int num=0;
        
        for(int i=0;i<s.length();i++)
        {
            if (isalpha(s[i])) // 看單詞
                temp += s[i];
            else if (isdigit(s[i])) // 得到數字
            {
                num *=10;
                num += int(s[i]-'0');
            }
            else // 其他字元
            {
                if (num) // 之前有遇到num的話
                {
                    auto it = v.end() - num; // 由後往前數
                    auto s = *it;
                    cout << *it;
                    // 放到最後面
                    v.erase(it);
                    v.push_back(s);
                    num =0; // reset
                }
                
                vector<string>::iterator it = find(v.begin(), v.end(), temp); // find temp
                if (temp!="" && it == v.end()) // 空字串 及 重複的不放
                    v.push_back(temp);
                cout << temp << s[i]; // 印出單字 跟 空白
                temp = ""; // reset
            }
        }
      
    }
    
    return 0;
}