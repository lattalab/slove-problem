// accepted with STL version
# include <iostream>
# include <string>
# include <cctype>
# include <vector>
# include <map>
# include <algorithm>
using namespace std;

bool compare(pair<char ,int> &a, pair<char, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;

    return a.second > b.second;
}

void sort_by_value(map<char, int> &m)
{
    vector<pair<char,int>> Ans; // Declare vector of pairs

    // Copy key-value pair from Map to vector of pairs
    for(auto& i:m)
        Ans.push_back(i);

    // Sort using function
   sort(Ans.begin(), Ans.end(), compare);

   // Print the sorted value
    for (auto& i : Ans) 
    {
        if ('A' <= i.first && i.first <= 'Z' && i.second > 0)
            cout << i.first << ' ' << i.second << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    
    getchar(); // 讀掉換行
    string s;
    map<char ,int> count;

    while(n--)
    {
        getline(cin,s);
        for(int i =0;i<s.length(); i++)
        {
            char key = toupper(s[i]);
            if (count.find(key) != count.end())
                count[key] += 1;
            else
                count[key] = 1;
        }
    }
    sort_by_value(count);
    
    return 0;
}