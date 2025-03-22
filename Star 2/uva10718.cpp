// Accepted
#include <iostream>
#include <string.h>
using namespace std;
int binary[64];
void convert_binary(long long int n){
    int idx = 0;
    while(n){
        // represent from low to high
        // index 0 is the lowest bit
        binary[idx++] = n % 2;  
        n /= 2;
    }
}
int main(){
    long long int n, l, u;
    while(cin >> n >> l >> u){  
        long long int ans = 0;  // the answer
        // convert n to binary
        memset(binary, 0, sizeof(binary));
        convert_binary(n);

        for(int i = 31; i >= 0; i--){
            if ((ans | (1LL << i)) > u) continue;   // if exceed the upper bound, skip
            /* 
                if lower bound is smaller than 2^i, set the bit to 1
                if the bit is 0, set the bit to 1
                if the bit is 1, to make the mask smaller, set the bit to 0
            */
            if (((ans | (1LL << i)) <= l) || (!binary[i])) 
                ans |= (1LL << i);
        }
        cout << ans << endl;
    }
    return 0;
}