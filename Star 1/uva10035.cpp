// accepted
# include <iostream>
using namespace std;
int main()
{
    int a,b;
    while(cin >> a && cin >> b && (a || b))
    {
        int count =0 , temp=0;

        bool carry =0;
        while(a || b) //任一個大於零繼續
        {
            int ta = a%10 , tb = b%10;
            temp = ta+tb;

            if (carry)
                temp += 1;

            if(temp >=10) // have carry
            {
                count ++;
                carry = 1;
            }  
            else
            {
                carry = 0;
            } 

            a/=10; b/=10;
        }

        if (count == 1)
            cout << count << " carry operation." << endl;
        else if (count >0)
            cout << count << " carry operations." << endl;
        else
            cout << "No carry operation." <<endl;
    }
    return 0;
}