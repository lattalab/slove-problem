// accepted
#include <iostream>
using namespace std;
#define BOUND 10001
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int m, n, t;
    while(cin >> m >> n >> t){

        int dp[BOUND] = {0};

        for (int i = 1; i < BOUND; i++) {
            dp[i] = -1; // represent impossible
        }

        for (int i = 1; i <= t; i++) {
            /* 
                trace from the beginning,
                once we can eat a burger, we can eat it in the next minute.
            */
            if (i >= m && dp[i - m] != -1) {
                dp[i] = dp[i - m] + 1;
            }
            if (i >= n && dp[i - n] != -1) {
                dp[i] = MAX(dp[i], dp[i - n] + 1);
            }
        }

        // print the result
        int count = 0;
        while(dp[t] == -1){
            t--;
            count++;
        }
        if (count > 0) {
            cout << dp[t] << " " << count << endl;
        } else {
            cout << dp[t] << endl;
        }
    }
    return 0;
}