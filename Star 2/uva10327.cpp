// accepted
# include <iostream>
# include <vector>
# include <sstream>
using namespace std;
int main()
{
    int n, v[1005];
    while(cin >> n)
    {
        for(int i=0;i<n;i++)
            cin >> v[i];
        
        int count=0;
        for(int i=n-1; i>0;i--) // run size-1 times
        {
            for(int j=0; j<i ;j++) // compare from 0~size-i
            {
                if (v[j] > v[j+1])
                {
                    int temp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = temp;

                    count ++;
                }
            }
        }
        cout << "Minimum exchange operations : " << count <<endl;
    }
    return 0;
}