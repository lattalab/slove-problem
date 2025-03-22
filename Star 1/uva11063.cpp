// accepted
# include <iostream>
# include <map>
using namespace std;
int main()
{
    int num, cases =1;
    while (cin >> num)
    {
        int arr[num];
        for(int i=0;i<num;i++)
        {
            cin >> arr[i];
        }

        map<int,int> mp;
        bool b2 = true;
        for(int i=0;i<num;i++)
        {
            for(int j=i;j<num;j++)
            {
                int sum = arr[i] + arr[j]; // bi + bj
                mp[sum]++; // 紀錄出現的
                // 有出現過多次就不是b2 數列 + 非正整數 + bi > bj
                if (mp[sum] > 1 || arr[i]<1 || arr[i] > arr[j]) 
                    b2 = false;
            }
        }
        cout << "Case #" << cases++ << ": ";
        if (b2)
            cout << "It is a B2-Sequence.\n\n";
        else
            cout << "It is not a B2-Sequence.\n\n";
    }
    
    return 0;
}