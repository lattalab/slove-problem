// accepted
# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
using namespace std;
int second_output(vector<int> &v, int target)
{
    // 找input中 跟 target一樣的 總數目
    // target 為使 所有絕對值相加的所有可能值
    int count =0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i] == target)
            count ++;
    }
    return count;
}
int main()
{
    int n;
    while (cin>>n)
    {
        vector<int> v;
        int num;
        for(int i=0;i<n;i++)
        {
            cin>> num;
            v.push_back(num);
        }

        sort(v.begin(),v.end());

        if (n%2 ==1) // odd numbers
            cout << v[n/2] << " " << second_output(v, v[n/2]) <<" " << 1 <<endl;
        else // 偶數的話，有兩種可能 (類似uva10041的概念)
        {
            if (v[n/2-1] == v[n/2])
                cout << v[n/2] << " " << second_output(v, v[n/2]) 
                     <<" " << 1 <<endl;
            else
            {
                // 在第三個output中，v[n/2-1]~v[n/2]之間的整數都能算出同樣的答案
                cout << min(v[n/2-1],v[n/2]) << " "
                     << second_output(v, v[n/2-1]) + second_output(v, v[n/2]) 
                     << " " << v[n/2]-v[n/2-1] +1 << endl;
            }
        }
    }
    
    return 0;
}