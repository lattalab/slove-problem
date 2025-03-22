#include <iostream>
#include <string.h>
using namespace std;

#define bound 100

void store_num_into_array(int num, int arr[])
{
    int i = 0;
    while (num)
    {
        arr[i] = num % 10;
        num /= 10;
        i++;
    }
}

int main()
{
    long a, b;     // 2 input number
    int n1[bound], n2[bound]; // store each digit of the input number
    while (cin >> a >> b && (a || b))  // input 2 number
    {
        // initialize n1 and n2
        memset(n1, 0, sizeof(n1));
        memset(n2, 0, sizeof(n2));
        // put each digit into array
        store_num_into_array(a, n1);
        store_num_into_array(b, n2);

        int temp; // calculate the sum of each digit
        int count = 0; // count the number of carry
        bool carry = 0; // whether to carry out
        for (int i=0; i<bound; i++){
            temp = n1[i] + n2[i];   // sum of each digit
            
            if (carry){
                temp +=1;  // carry out
            }

            // modify the carry
            if (temp >= 10){
                count ++;
                carry = 1;
            }
            else{
                carry = 0;
            }
        }

        // print the desired result
        switch(count)
        {
            case 0:
                cout << "No carry operation." <<endl;
                break;
            case 1:
                cout << count << " carry operation." << endl;
                break;
            default:
                cout << count << " carry operations." << endl;
                break;
        
        }

    }
    return 0;
}