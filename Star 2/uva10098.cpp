// accepted
# include <iostream>
# include <algorithm>
using namespace std;
// next_permutation() to order the sequence.
int main()
{
    int n;
    string s;

    cin >> n;
    while(n--)
    {
        cin >> s;
        sort(s.begin(),s.end()); // sort by lex order
        
        do
        {
            cout << s <<endl;
        } while (next_permutation(s.begin(),s.end()));

        s.clear();
        cout << endl;
    }
    return 0;
}