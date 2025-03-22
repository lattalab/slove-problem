//accepted
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int num = 0;
    while(cin >> n && n){
        cout << "Game " << ++num << ":" << endl; // print the game number

        vector<int> a(n);
        for(int i = 0; i < n; i++){ // get password
            cin >> a[i];
        }

        vector<int> b(n); // get the guess of the password
        while(1){
            bool flag = 0;
            for(int i = 0; i < n; i++){
                cin >> b[i];
                flag = (flag || b[i]); 
            }
            if (!flag) break; // if all 0, break the loop

            int countA = 0, countB = 0; // count the number of A and B
            vector<int> Remainder_A, Remainder_B; // reduct the a[i] == b[i]
            for (int i = 0; i < n; i++){
                if (a[i] == b[i]) countA++; // if the number is in the same position, count A
                else {
                    Remainder_A.push_back(a[i]);
                    Remainder_B.push_back(b[i]); // if not, push it to the vector
                }
            }

            for (auto i = Remainder_B.begin(); i != Remainder_B.end(); i++){
                auto j = find(Remainder_A.begin(), Remainder_A.end(), *i); // find the number in b
                if (j != Remainder_A.end()){ // if found, count B and erase it from b
                    countB++;
                    Remainder_A.erase(j);
                }
            }
            cout << "    (" << countA << "," << countB << ")" << endl; // print the result
        }
    }
    return 0;
}
