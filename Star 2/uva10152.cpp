// accepted
# include <iostream>
using namespace std;
// 由後往前比對, 跟stack先放會在最下面
int main()
{
    int t;
    string buf;
    cin >> t; //testcase
    while(t--)
    {
        int n;
        cin >> n;
        getline(cin , buf); // read newline

        string orig[n], target[n];
        for(int i=0;i<n;i++)
            getline(cin,orig[i]);

        for(int i=0;i<n;i++)
            getline(cin,target[i]);

        int pt=n-1,dt=n-1;
        while(pt >= 0)
        {
            if(orig[pt] == target[dt]) 
            {
                dt--;
            }
            pt--;
        }
        for(int i =dt;i>=0;i--)
            cout << target[i] <<endl;

        cout << endl;
    }
    return 0;
}