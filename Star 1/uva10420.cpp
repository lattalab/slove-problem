// accepted
# include <iostream>
# include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    getchar(); // read new line
    map<string,int> mp;

    while(n--)
    {
        string s, name;
        getline(cin , s , ' '); // read country
        getline(cin, name); // read name
        mp[s]++;
    }

    for(auto i:mp)
        cout << i.first << " " << i.second << endl;
    return 0;
}