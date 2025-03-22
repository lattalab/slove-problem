// accepted
# include <iostream>
# include <vector>
# include <algorithm>
# include <iomanip>
using namespace std;
/*
題目大意: 
給予m*n個 10x10的土地，有m*n個海拔高度會流水下來(預設低的流光，再換上面的流)
要找出水位線跟會被覆蓋的海拔高度
*/
int main()
{
    int m,n,region=1;
    while(cin >> m >> n && (m && n))
    {
        vector<int> v;
        int num;
        for(int i=0;i<m;i++) // 海拔高度
        {
            for(int j=0;j<n;j++)
            {
                cin >> num;
                v.push_back(num);
            }
        }
        double volume; // 總體積
        cin >> volume;

        sort(v.begin(), v.end()); // 低的先流
        double level; // water-level
        int sum=0,count=0; 
        volume /= 100;

        //volume = h * 100 = [(h−H[0])+(h−H[1])+⋯+(h−H[i])] * 100
        // 平均水位理應至多只會蓋過目前的 H[i]
        // 平均水位 < H[i+1]
        for(int i=0;i<v.size();i++)
        {
            sum += v[i]; count++;
            level = ((volume + sum) / count);
            if (level <= v[i+1])
                break;
        }

        double percentage = double(count)/(m*n) * 100;

        cout << "Region " << region++ << endl;
        cout << fixed << setprecision(2) << "Water level is " << level << " meters.\n";
        cout << percentage << " percent of the region is under water.\n\n";
        
        }
    return 0;
}