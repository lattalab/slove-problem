// accepted
# include <iostream>
# include <cmath>
using namespace std;
int binary_one(int n)
{
    // 從2^n看
    // ex: 21 = 16 + 4 + 1
    int count =0 ;
    for(int i=14;i>=0;i--)
    {
        int temp =pow(2,i);
        if (n>= temp)
        {
            n -= temp;
            count ++;
        }
    }
    return count;
}
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int num;
        cin >> num;

        int ten = binary_one(num); // 十進位轉二進位
        int hex = 0; //十六進位轉二進位
        // 16 = 2^4
        // 2 6 5 (hex) = 0010 0110 0101 (binary)
        while(num >0)
        {
            hex += binary_one(num%10);
            num /= 10;
        }

        cout << ten << " " << hex << endl;
    }
    
    return 0;
}