// accepted
# include <iostream>
using namespace std;
int main()
{
    int n, tc=0;
    cin >> n;
    while(n--)
    {
        int A,F;
        cin >> A >> F;
        for(int i=0;i<F;i++) // output F time
        {
            if (tc++) // case separate with a line
                cout << endl;

            for(int j=1;j<=A;j++) // upper region
            {
                for(int k=1;k<=j;k++) // print the same amount as j
                    cout << j;

                cout << endl; // separate with endl
            }
            for(int w = A-1;w>0;w--) // lower region
            {
                for(int k=1;k<=w;k++) // print the same amount as w
                    cout << w;
                
                cout << endl; // separate with endl
            }
        
        }
    }
    return 0;
}