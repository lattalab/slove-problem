// accepted
# include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m,n,q;
        cin >> m >> n >> q;
        cout << m << " " << n << " " << q << endl;
        char arr[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                cin >> arr[i][j];
        }
        while(q--)
        {
            int x,y;
            cin >> x >> y;
            int ans=1,side=1;
            bool stop = false;
            while(!stop) // 直接跑遍整個長方形
            {
                for(int i= x+side;i>=x-side;i--)
                {
                    for(int j=y+side;j>=y-side;j--)
                    {
                        if (i<0 || i>=m || j<0 || j>=n)
                            stop = true;
                        if (arr[i][j] != arr[x][y])
                            stop = true;
                    }
                }
                ans +=2; side+=1;
            }
            cout << ans-2 << endl;
        }   
    }
    return 0;
}