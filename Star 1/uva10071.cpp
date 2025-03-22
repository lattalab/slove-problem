// accepted
#include <iostream>
using namespace std;
int main()
{
    int v,t;
    while(cin >> v >> t)
    {
    // 平均距離*時間 -> 畫v-t圖
    cout << 2 * v * t << endl;
    }
    return 0;
}