#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int cases;  // number of test cases
    cin >> cases;
    while (cases--) {
        int n;
        cin >> n;   // number of cows

        vector<vector<int>> arr(n);   // ith cow's production
        for (int i = 0; i < n; i++) {
            int cycle, production;
            cin >> cycle;

            arr[i].resize(cycle);
            for (int j = 0; j < cycle; j++) {
                cin >> production;
                arr[i][j] = production;
            }
        }

        // find the period
        int period = 1;
        for (int i = 0; i < n; i++) {
            period = lcm(period, arr[i].size());
        }

        int passday = 0;
        vector<int> record; // 記錄第幾天吃掉牛
        bool cowDeleted = false;    // 用布林變數來判斷是否有刪除牛
        while (true) {   // ith day

            int min = arr[0][passday % arr[0].size()], idx = 0;
            bool multiple = false;
            for (int i = 1; i < n; i++) { // nth cow
                if (arr[i][passday % arr[i].size()] < min) {
                    multiple = false;
                    min = arr[i][passday % arr[i].size()];
                    idx = i;
                }
                // multiple cows produce the same amount of milk
                else if (arr[i][passday % arr[i].size()] == min) {
                    multiple = true;
                }
            }

            if (!multiple) {  // eat the least milk cow
                arr.erase(arr.begin() + idx);
                n -= 1; // decrease the number of cows
                cowDeleted = true;
                record.push_back(passday + 1); // record the day cow is eaten
            }

            passday++;

            if (passday % period == 0) {
                if (!cowDeleted) {
                    break;
                } else {
                    cowDeleted = false;
                }
            }

            if (n == 0) break; // all cows are eaten
        }

        if (record.empty()) {
            cout << n << " 0" << endl;
        } else {
            // access the last element of the vector
            cout << n << " " << record.back() << endl;
        }
    }
    return 0;
}