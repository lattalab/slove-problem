// accepted
# include <iostream>
using namespace std;
// 觀念: gcd, lcm ,排容原理, binary form
# define ll long long int
ll gcd(ll a , ll b)
{
    while((a%=b) && (b%=a));
        return a+b;
}
ll LCM(ll a, ll b)
{
    return a*b/gcd(a,b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    int arr[16];
    while (cin >> n >> m)
    {
         // m inputs
        for(int i=0;i<m;i++)
            cin >> arr[i];
    
        ll lcm ,ans = 0 ,count;
        /*
        m =2;
        1<<m : 001 , 010 , 011 , 100(不看)
        i & (1<<j): 選到arr[0], 選到 arr[1] , 選到arr[0]跟arr[1]
        */
        // (1<<m) represent as binary to find all possibility
        int range = (1<<m);
        for(int i=1; i< range; i++)
        {
            lcm = 1;
            count =0;
            for (int j=0; j<m; j++)
            {
                if (i & (1<<j)) // 看arr[j] 有沒有被選取到
                {
                    lcm = LCM(lcm,arr[j]);
                    if (lcm > n) 
                        break;
                    count++;
                }
            }
            if (count%2)
            {
                //排容（奇數個因數）
                ans += n / lcm;
            } 
            else 
            {
                //排容（偶數個因數）
                ans -= n / lcm;
            }
        }
        cout << n-ans <<endl; // 全部個數- 很多set的倍數集合
    }
    return 0;
}