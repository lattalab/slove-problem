// accepted
# include <iostream>
# include <sstream>
using namespace std;
int gcd(int a, int b)
{
    return (!b) ? a:gcd(b,a%b);
}
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        int arr[105] ,num, idx=0;
        string s;
        getline(cin,s);
        // use sstream to get numbers
        stringstream ss(s); // constructor
        while(ss >> num)
        {
            arr[idx++] = num;
        }

        int maxGCD = 1;
        // O(100*100) 可窮舉
        for(int i=0;i<idx;i++)
        {
            for(int j=i+1;j<idx;j++)
            {
                maxGCD =max(maxGCD, gcd(arr[i],arr[j])); // update and assign
            }
        }
        cout << maxGCD <<endl;
    }
    
    return 0;
}