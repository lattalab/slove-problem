#include <iostream>
using namespace std;
#define bound 1000001
bool prime[bound];

int reverse(int num){
    int r = 0;
    while(num){
        r += num%10;
        num /= 10;
        r *= 10;
    }
    r /= 10;
    return r;
}

int main(){
    // create a prime table
    fill(begin(prime), end(prime), true);
    prime[0] = prime[1] = false;
    for (int i = 2; i<bound; i++){
        if (prime[i]){
            for (int j = 2*i; j<bound; j+=i){
                prime[j] = false;
            }
        }
    }

    int n;
    while(cin >> n)
    {
        bool p = prime[n];
        int r = reverse(n);
        bool emirp = prime[r];
        if (!p)
            cout << n << " is not prime.\n";
        else if (p && emirp && n!=r)
            cout << n << " is emirp.\n";
        else
            cout << n << " is prime.\n";
    }

    return 0;
}