// accepted
# include <iostream>
# include <map>
# include <algorithm> // swap
using namespace std;
int main()
{
    int w,h;
    while(true)
    {
        bool flag = true; // 檢查指標
        map<int,int> mp; // 用map來存值 + 計算出現次數
        map<pair<int,int>, int> p; // 用map來存每個長方形 + 計算出現次數
        int wide[6],hight[6]; // 存wide, hight

        for(int i=0;i<6 ;i++)
        {
            if (!(cin >> w >> h)) return 0; // stop input

            if (w > h)     // 使 h 永遠大於 w
                swap(w,h);

            mp[w]++; mp[h]++;
            p[make_pair(w,h)]++;
            wide[i] = w; hight[i] = h;

            if (mp.size() > 3) // 長方體長寬高 頂多 三個都不一樣
                flag = false;
        }

        for(auto i:mp)
        {
            if (i.second %4 != 0) // 邊長個數會是4的倍數
                flag = false;
        }
        for(auto i:p)
        {
            if (i.second %2 != 0) // 每個面會成對出現
                flag = false;
        }

        // wide , hight由小到大排序  
        sort(wide,wide+6);
        sort(hight,hight+6);

        /*
        3 4
        3 4
        3 5
        3 5
        4 5
        4 5
        第一組短邊 = 第二組短邊 , 第一組長邊 = 第三組短邊 , 第二組長邊 = 第三組長邊
        */

        if (!(wide[0] == wide[2] && hight[0] == wide[4] && hight[2] == hight[4]))
            flag = false;


        if (flag)
            cout << "POSSIBLE" << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}