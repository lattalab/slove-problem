// accepted
# include <iostream>
# include <string>
# include <iomanip>
using namespace std;
int number[4] = {10000000, 100000, 1000, 100};
string str[4] = {"kuti", "lakh", "hajar", "shata"};
void transfer(long long int num)
{
    if (num>= number[0])
    {
        transfer(num/number[0]);
        cout << " kuti";
        transfer(num%number[0]);
    }
    else
    {
        for(int i=0;i<4;i++)
        {
            if(num>= number[i])
            {
                int temp = num/number[i];
                num = num%number[i];
                cout << " " << temp << " " << str[i];
            }
        }
        if (num)
            cout << " " << num;
    }
}
int main()
{
    int time =1;
    long long int num;
    while(cin >> num)
    {
        cout << setw(4) << time << ".";
        time++;

        if (!num)
            cout << " 0" << endl;
        else
        {
            transfer(num);
            cout << endl;
        }   
    }
    return 0;
}