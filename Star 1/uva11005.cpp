// accepted
# include <iostream>
# include <map>
using namespace std;
int main()
{
    int t, cases = 1;
    cin >> t; // testcase
    bool flag = false;
    while(t--) 
    {
        map<int, int> mp;
        for(int i=0;i<36;i++)
            cin >> mp[i]; // cost for number

        int q,num;
        cin >> q; // query numbers
        if (flag) // between case and case need a line space
            cout << endl;
        cout << "Case " << cases++ << ":\n";
        while(q--)
        {
            cin >> num;
            int min =0 , sum[37] = {0};
            for(int i=2;i<=36;i++)
            {
                int temp = num,s=0;
                while(temp) // let a number represent in base i
                {
                    s += mp[temp%i]; // calculate the total cost
                    temp/=i;
                }
                sum[i] = s; // record the sum
                if (min == 0 || s < min) // find min
                {
                    min = s;
                }
            }
            cout << "Cheapest base(s) for number " << num 
                 << ":";
            for(int i=2;i<=36;i++)
            {
                if (sum[i] == min)
                cout <<" " << i;
            }
            cout << endl;
        }
        flag = true;
    }
    return 0;
}