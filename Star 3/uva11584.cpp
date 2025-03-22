// Accepted
#include <iostream>
#include <limits>
using namespace std;

#define MAX 1005
#define INF numeric_limits<int>::max()  // INF = 2147483647
int dp[MAX];    // dp[i] = min cut of the first of i characters in string

bool is_palindrome(string &s, int left, int right){
    // trace from left and right to the middle
    // until left > right
   while(left <= right){
        if (s[left] != s[right]) return false;
        left++;
        right--;
   }
   return true;
}

int main(){
    int cases;
    cin >> cases;   // how many input number
    while(cases--){
        // input string
        string s;
        cin >> s;
        int len = s.length();

        // initial dp
        /*
            Note here, memset is not working for int array,
            because memset is for char array
        */
        for (int i = 1; i <= len; i++) dp[i] = INF;
        dp[0] = 0;

        // update dp
        for(int i = 1; i <= len; i++){
            // find the first i characters 's least cut
            for(int j = 1; j <= i; j++){ 
                if (is_palindrome(s, j-1, i-1)){
                    // we can divide the string into two parts
                    // the first part is s[j-1]
                    // the second part is s[j, i-1]
                    // the new comming chcaracter can combine with the second part
                    dp[i] = min(dp[i], dp[j-1] + 1);
                }
            }
        }
        // output
        cout << dp[len] << endl;
    }
    return 0;
}