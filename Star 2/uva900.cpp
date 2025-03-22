#include <iostream>
using namespace std;
long long dp[51] = {0, 1, 2};
// 公式剛好是費式數列
long long fib(int n){
    if (dp[n] != 0) return dp[n];
    return dp[n] = fib(n-1) + fib(n-2);
}
int main(){
    int n;
    while(cin >> n && n){
        if (n == 1 || n == 2){
            cout << dp[n] << endl;
            continue;
        }
        cout << fib(n) << endl;
    }
    return 0;
}