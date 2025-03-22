// accepted
# include <iostream>
# include <vector>
# include <iomanip>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, sum=0;
        cin >> n;
        vector<int> v;
        for(int i=0;i<n;i++) // get input
        {
            int num;
            cin >> num;
            v.push_back(num);
            sum +=num; // accumulate sum
        }

        float avg = sum/n;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if (v[i] > avg) // find who is higher than average
                count ++;
        }
        // output the percentage 
        cout << fixed << setprecision(3)
             << count/(double)n *100 <<"%" << endl; 
    }
    return 0;
}