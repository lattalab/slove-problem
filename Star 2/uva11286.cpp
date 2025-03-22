// accepted
# include <iostream>
# include <sstream>
# include <map>
# include <algorithm>
using namespace std;
/*
題意: 大學新鮮人 會選5門課為一組合
要找出 有最多人選的組合 "人數"
如果同時最多人選的組合 不止一個 -> 算累計總人數
*/
int main()
{
    int n;
    while(cin >> n && n)
    {
        int max = 0;
        map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            int arr[5]; // get select course
            for(int j=0;j<5;j++)
                cin >> arr[j];
            sort(arr,arr+5); // ascending order

            stringstream ss; // change number to string
            for(int i=0;i<5;i++)
                ss << arr[i];
            string s;
            ss >> s;

            mp[s]++; // hash
            if (mp[s] > max) // record max
                max = mp[s];
        }

        // 如果有很多組合 = max , 這些人數要相加
        int sum=0;
        for(auto i:mp)
        {
            if (i.second == max)
                sum += i.second;
        }

        cout << sum <<endl;
    }
    return 0;
}