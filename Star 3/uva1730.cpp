// accepted
#include <iostream>
using namespace std;

int main(){
    long long n;
    while(cin >> n && n){
        long long ans = 0;
        long long i = 1;
        while (i <= n){
            long long times = n/i;  // occurance
            long long start = i;    // the first number
            long long end = n/times;  // the last number
            // the sum of the arithmetic sequence
            ans += ((start+end) * (end-start+1) / 2) * times;
            i = end + 1; // skip the numbers that have been calculated
        }
        // because MSLCM (1) is not calculated
        cout << ans - 1 << endl;
    }
    return 0;
}