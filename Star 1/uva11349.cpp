// accepted QQ
# include <iostream>
using namespace std;
// 轉成一維陣列 頭尾相比，比到中間 即可判斷有沒有對稱
int main()
{
    int t, cases=1;
    cin >> t;
    while(t--)
    {
        int n;
        char ch;
        cin >> ch >> ch >> n;
            
        bool sym = true;
        long long int arr[n*n];
        for(int i=0 ;i < n*n;i++)
        {
            cin >> arr[i];
        }   

        // 中心點也要看
        for(int j=0;j<=n*n/2;j++)
        {
            if (arr[j] != arr[n*n-1-j] || arr[j]<0 || arr[n*n-1-j]<0)
            {
                sym = false;
                break;
            }
        }

        if (sym)
            cout << "Test #" << cases++ << ": Symmetric.\n";
        else
            cout << "Test #" << cases++ << ": Non-symmetric.\n";
    }
    return 0;
}