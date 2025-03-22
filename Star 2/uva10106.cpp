// accepted
# include <iostream>
# include <vector>
# include <algorithm>
// 用陣列模擬大數乘法 (like 大數加法)
using namespace std;
int main()
{
    string x, y;
    while (cin >> x >> y)
    {
        if (y.length() > x.length()) // 將y設成長度較小的那個
            swap(x,y);

        if (y == "0") // 某東西*0是0
        {    
            cout << 0 <<endl;
            continue;
        }

        vector<int> X,Y;
        int xlen = x.length(), ylen = y.length();
        for(int i=0;i<xlen;i++)
            X.push_back((x[i]-'0'));
        for(int i =0;i<ylen;i++)
            Y.push_back((y[i]-'0'));

        // 大數乘法
        reverse(X.begin(),X.end());
        reverse(Y.begin(),Y.end());
        int v[510] ={0};
        for(int i=0;i<xlen;i++)
        {
            for(int j=0;j<ylen;j++)
            {
                v[i + j] += X[i]*Y[j];
                v [i+j+1] += v[i+j]/10;
                v[i+j] = v[i+j]%10;
            }   
        }

        int anslen = xlen + ylen;
        while(anslen >1 && !v[anslen-1]) anslen--;
        for(int i=anslen-1;i>=0;i--)
           cout <<v[i];
           
        cout << endl;
        x.clear(); y.clear();
    }
    return 0;
}