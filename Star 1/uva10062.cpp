// accepted
# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;
bool compare(pair<int,int> a, pair<int,int> b)
{
    if (a.first == b.first)
        return a.second > b.second;

    return a.first < b.first;
}
int main()
{
    string str;
    bool flag = false;
    while(getline(cin, str))
    {
        if (flag) // 輸入跟輸出之間隔一行空白(第二筆之後)
            cout << endl;
        vector< pair<int, int> > v;
        for (int i=0;i<256;i++)
        {
            v.push_back(make_pair(0,i));
        }
        for(int i=0;i<str.length();i++)
        {
            v[int(str[i])].first +=1;
        }

        sort(v.begin(),v.end(), compare);
        for(int i=0;i<v.size();i++)
        {
            if (v[i].first)
                cout<< v[i].second << " " << v[i].first << endl;
        }

        str.clear();
        flag = true;
    }
    return 0;
}