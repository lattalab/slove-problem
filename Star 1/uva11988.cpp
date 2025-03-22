// accepted
# include <iostream>
# include <list>
using namespace std;
/*
note: 
press Home: move to the frontest
press End : move to the latest
*/ 
int main()
{
    string s;
    while(getline(cin,s))
    {
        list<char> l;
        list<char>::iterator it = l.begin();

        // first time, l is empty
        // if we insert, 'w', 'n' -> we get "wn"

        for(int i=0;i<s.length();i++)
        {
            switch (s[i])
            {
            case '[':
                it = l.begin();
                break;
            case ']':
                it = l.end();
                break;
            default:
                l.insert(it,s[i]); // insert element before it
                break;
            }
        }

        for(auto i:l)
            cout << i ;
        cout << endl;
    }
    return 0;
}