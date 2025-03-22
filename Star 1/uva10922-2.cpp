// accepted
# include <iostream>
# include <string>
using namespace std;
// 題意: 判斷這個數的總和是不是9的倍數，直到剩一位數
int main()
{
    string n;
    while(cin >> n && n!="0")
    {
        int count = 0, sum=0;
        for(int i=0;i<n.length();i++)
            sum += n[i]-'0';

        while (1)
        {
            if (sum %9)
                break;
            else if (sum == 9)
            {
                count++;
                break;
            }
            else
            {
                count++;
                int temp=0;
                while(sum)
                {
                    temp += sum%10;
                    sum/=10;
                }
                sum = temp;
            }
        }    

        if(count)
            cout << n << " is a multiple of 9 and has 9-degree " << count <<".\n";
        else
            cout << n << " is not a multiple of 9.\n";

        n.clear();
    }
    return 0;
}