// accepted
# include <iostream>
# include <cmath>
using namespace std;
int main()
{
    int t;
    cin >> t;
    string s;
    getline(cin, s); //remove newline
    while(t--)
    {
        getline(cin,s);
        int len = s.length();
        int number = sqrt(len+0.0);
        if (number * number != len)
        {
            cout << "INVALID" <<endl;
            continue;
        }

        for(int i=0;i<number;i++) // column
        {
            for(int j=0;j<number;j++) // row
            {
                int pos = i + j*number; // column major formula
                cout << s[pos];
            }
        }
        cout << endl;
    }
    return 0;
}