// accepted 太神奇了
# include <iostream>
# include <vector>
# include <sstream>
# include <string>
# include <algorithm>
using namespace std;
int main()
{
    int x;
    string s;
    while(cin >> x)
    {
        getline(cin,s); // remove newline after the num
        getline(cin,s);

        stringstream ss; // stringstream 讀入 用空格隔開的數字(可能有好幾個空格)
        vector<int> v;
        int num;
        ss << s;
        while(ss >> num) // 讀項數
        {
            v.push_back(num);
        }

        // 由次方少的開始微，減少計算量
        reverse(v.begin(), v.end()); // 反轉
        int sum=0;
        long long int exp =1; // x^n 的值
        for(int i=1;i<v.size();i++)
        {
            sum += v[i]*i*exp; // 等於 An * n * x^n-1
            exp*=x;
        }
        cout << sum << endl;

        // 清空stringstream
        ss.clear();
        ss.str(""); 

        // 清空vector
        v.clear();
    }
    return 0;
}