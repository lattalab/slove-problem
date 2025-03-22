// accepted
# include <iostream>
# include <queue>
# include <cmath>
using namespace std;
bool not_prime[1001] = {false}; // initial 0
bool record[1005];
int main()
{
    // 質數表 (多筆測資省時間)
    for(int i =2;i<1001;i++)
    {
        for(int j=i*i ;j<1001;j+=i) // 刪掉該質數的倍數
        {
            not_prime[j] = true;
        }
    }

    int s,t,cases=1;
    while(cin >> s >> t && (s && t))
    {
        cout << "Case " << cases++ << ": ";
        if (s == t) 
        {
            cout << 0 << endl;
            continue;
        }

        int min = -1;
        queue<pair<int,int>> q;
        q.push({s,0});

        for(int i =0 ;i<1005;i++)
            record[i] = false;

        while(!q.empty())
        {
            int now = q.front().first; // number for now
            int count=q.front().second; // spent time
            q.pop();

            if (now == t && (min<0 || count < min))
            {
                min = count;
                continue;
            }

            for(int i=2; i<now; i++)
            {   
                if (not_prime[i]) continue;
                if (now % i != 0) continue;
                if(now+i <= t && !record[now+i])
                {
                    q.push({now+i,count+1});
                    record[now+i] = true;
                }
            }
        }

        cout << min << endl;
    }
    return 0;
}