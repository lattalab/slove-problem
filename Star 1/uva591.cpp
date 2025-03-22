// accepted
# include <iostream>
using namespace std;
int main()
{
    int t, set =1;
    while(cin >> t && t)
    {
        int num[t], sum =0;
        for(int i=0;i<t;i++)
        {
            cin >> num[i];
            sum += num[i];
        }
        int avg = sum/t, count=0;
        for(int i=0;i<t;i++)
        {
            if (num[i] > avg)
                count += (num[i]-avg);
        }

        cout << "Set #" << set++ << endl;
        cout << "The minimum number of moves is " << count << ".\n\n";
    }
    return 0;
}