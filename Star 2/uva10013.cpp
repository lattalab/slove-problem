// accepted
# include <iostream>
using namespace std;
int sum[1000005] = {0};
int main()
{
    int n; // test case
    cin >> n;
    while(n--)
    {
        int len, a, b;
        cin >> len; // digit length

        int pointer=len-1 , c;
        bool carry = false; // to determine whether carry exists or not

        // 因為從高位元開始輸入，所以要反著key
        for(int i=0;i<len;i++)
        {
            scanf("%d %d",&a,&b);
            int temp = a + b;
            sum[pointer--] = temp;
        }

        for(int i=0;i<len;i++)
        {
            if (carry) // carry exist , plus it
                sum[i] += c;
            if (sum[i] >=10) // know that need to carry
            {    
                carry = true;
                c = sum[i]/10; // carry num to next digit
            }
            else
                carry = false;

            sum[i] = sum[i]%10; // change the value to right value
        }

        if (carry) // to check whether last digit have carry or not
            cout << c;

        for(int i=len-1;i>=0;i--)
            cout << sum[i];
        cout << endl;

        if (n > 0) // every output need to separate one line
        cout << endl; 
    }
    return 0;
}