// accepted
# include <iostream>
# include <vector>
using namespace std;
int main()
{
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        int day; //議會天數
        cin >> day;

        int party, h;
        vector<int> v;
        cin >> party; //幾個議會
        for(int i=0;i<party;i++)
        {
            cin >> h; //霸會參數
            v.push_back(h);
        }

        int count=0;
        for(int i=1;i<=day; i++)
        {
            if (i%7 == 6 || i%7 == 0) // 議會假日(星期五、星期六)
            {
                continue;
            }
            // 六 日 一 二 三 四 五
            bool workday[7] = {true,false,false,false,false,false,true}; 
            for(int j=0;j<v.size();j++)
            {
                /* 某個議會罷工 and 第一次遇到罷工(剔除重複罷工的議會) */
                if ((i%v[j] == 0) && (!(workday[i%7])))
                {
                    count ++;
                    workday[i%7] = true;
                }
            }
        }
        cout << count <<endl;
    }

    return 0;
}