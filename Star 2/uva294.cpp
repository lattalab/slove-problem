// accepted
# include <iostream>
# include <vector>
using namespace std;
bool not_prime[32000]; // initial 0
vector<int> v;
int main()
{
    // 建質數表
    for(int i =2;i<32000;i++)
    {
        if (!not_prime[i])
            v.push_back(i);
        for(int j=2*i ;j<32000;j+=i) // 刪掉該質數的倍數
        {
            not_prime[i] = true;
        }
    }

    long long int n , L , U;
    cin >> n;
    while(n--)
    {
        cin >> L >> U;
        int max =0 , Max_num=0;
        for(int i=L ; i<=U ; i++)
        {
            int p=1 , n=i;
            for(int j=0;j<v.size();j++)
            {
                int count=0;
                while (n% v[j] == 0)
                {
                    count++; //算有幾個這個因數
                    n/= v[j]; 
                }
                p *= (count+1);
                if (n==1) break;
            }
            if (p > max)
            {
                max = p;
                Max_num = i;
            }
        }

        cout << "Between " << L << " and " << U
             << ", " << Max_num << " has a maximum of "
             << max << " divisors.\n";
    }
    return 0;
}