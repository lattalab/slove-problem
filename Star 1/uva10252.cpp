// accepted
# include <iostream>
# include <string>
using namespace std;
// 統計共同的部分 跟 最小重複的次數
int main()
{
    string a,b;
    while(getline(cin, a) && getline(cin, b))
    {
        if (a== "" || b=="")
        {
            cout << endl;
            continue;
        }
        int sum[26] ={0}, sum2[26]={0};
        for(int i=0;i<a.length();i++)
        {
            sum[a[i]-'a'] ++;
        }
        for(int j=0;j<b.length();j++)
        {
            sum2[b[j]-'a']++;
        }
        
        for(int k=0;k<26;k++)
        {
            if (sum[k] && sum2[k])
            {
                for(int i=0 ;i< min(sum[k],sum2[k]); i++)
                    cout << char(k+'a');
            }
        }

        cout << endl;
    }
    return 0;
}