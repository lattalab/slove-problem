// accepted
# include <iostream>
# include <algorithm>
using namespace std;
int main()
{
    int n,d,r;
    while (cin >> n >> d >> r)
    {
        if (n==0 && d==0 && r==0)
            break;

        int early[n],night[n];
        for(int i=0;i<n;i++)
            cin >> early[i];
        for(int i=0;i<n;i++)
            cin >> night[i];

        sort(early,early+n);
        sort(night,night+n);

        int sum=0;
        for(int i=0;i<n;i++) // 小的配大的 使其平均達d
        {
            int temp = early[i] + night[n-1-i] - d;
            if (temp >0)
                sum += temp*r;
        }
        cout << sum << endl;
    }
    
    return 0;
}