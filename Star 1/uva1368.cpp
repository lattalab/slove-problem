// accepted
# include <iostream>
# include <map>
using namespace std;
string sequence[60];
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int m,n;
        cin >> m >> n;
        for(int i=0;i<m;i++) // m個長度為n的sequence
        {
            cin >> sequence[i];
        }

        int hamming = 0;
        string s = "";
        for(int i=0;i<n;i++) // search sequence from 1st index
        {
            map<char,int> mp; // use map to sum the occurence time.
            for(int j=0;j<m;j++)
            {
                mp[sequence[j][i]] ++;
            }

            char ch;
            int max = -1;
            for(auto k:mp) // trace the map
            {
                if (max == -1 || k.second > max) // find most frequently
                {
                    max = k.second;
                    ch = k.first;
                }
                if (k.second == max && k.first < ch) // select the minimum lex order
                {
                    ch = k.first;
                }
            }
            s += ch; 
            hamming += (m-max);
        }
        cout << s << endl << hamming << endl;
    }
    return 0;
}