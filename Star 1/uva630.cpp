// accepted
# include <iostream>
# include <algorithm>
using namespace std;
// 用sort比較破題
void search(string s[],string t, int len)
{
    cout << "Anagrams for: " << t << endl;
    int count =1;
    string test = t;
    sort(test.begin(),test.end());
    for(int i=0;i<len;i++) // find if whether the content has occured
    {
        string temp = s[i];
        sort(temp.begin(),temp.end());
        
        if (test == temp)
            cout << "  " << count++ <<") " << s[i] <<endl;
    }
    if (count == 1)
        cout << "No anagrams for: " << t << endl;
}
int main()
{
    int t, n;
    bool flag = false;
    cin >> t;
    string buf;
    getline(cin , buf); // read newline
    while (t--)
    {
        if (flag)
            cout << endl;
        string s[1010] , test;
        getline(cin, buf); // empty line
        cin >> n;
        getline(cin, buf); //read newline
        for(int i=0;i<n;i++)
        {
            getline(cin , s[i]);
        }

        while(getline(cin, test) && test!= "END") // input until END
        {
            search(s, test, n);
            test.clear();
        }
        flag = true;
    }
    
    return 0;
}