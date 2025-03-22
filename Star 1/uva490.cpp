// accepted
# include <iostream>
# include <string>
using namespace std;
int main()
{
    string s[101];
    int max=0;
    int row =0;
    while(getline(cin,s[row]))
    {
        if (max < s[row].length())
        max = s[row].length();

        row++;
    }

    for(int idx = 0; idx<max;idx++)
    {
        for(int i =row-1;i>=0;i--)
        {
            if (idx < s[i].length())
            cout << s[i][idx];
            else //超出範圍要印出空格
            cout << " ";
        }
        cout <<endl;
    }
    return 0;
}