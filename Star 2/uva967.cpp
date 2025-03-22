// accepted
# include <iostream>
# include <vector>
using namespace std;
// base prime table
const int maxn = 1000002;
int not_prime[maxn] = {0};

// check for circular prime , paramemter is the prime number we want to test
int check(int num)
{   
    if (not_prime[num])
        return 0;
    // find the digit first:
    int n = num , digit =0;
    while(n)
    {
        n /= 10;
        digit++;
    }

    n = num;
    int base = 1;
    for(int i=1; i<digit ; i++)
        base *= 10;

    while(digit--) // circular the digit
    {
        int temp;
        temp = n%base *10 + (n/base);
        if (not_prime[temp]) // if new digit is not a prime number.
            return 0; // no circular number
        n = temp;
    }
    return 1;
}
int main()
{
    // speed-up
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // record the circular number, to remove redundant calculation.
    vector<int> circular;

    not_prime[0] = not_prime[1] = 1;
    for(int x = 2; x< maxn ; x++)
    {
        if (not_prime[x] == 0) // if prime number occur;
        {
            if(check(x)) // check circular prime number simultaneously.
                circular.push_back(x);
            // This prime number's multiple will not be a prime number.
            for(int y=2*x; y <maxn; y += x)
            {
                not_prime[y] = 1;
            }
        }
    }
    
    int i,j;
    while(cin >> i)
    {
        if (i == -1) // only -1 imply end the program
            break;
        cin >> j;

        int ans = 0; // final answer
        for(int k = 0 ; k<circular.size() ; k++)
        {
            // between i~j 
            if (circular[k] <i)
                continue;
            if (circular[k] >j)
                break;
            
            ans += 1;
        }
        // output
        if (!ans)
            cout << "No Circular Primes." << endl;
        else if (ans == 1)
            cout << "1 Circular Prime." << endl;
        else
            cout << ans << " Circular Primes." << endl;
    }
    return 0;
}