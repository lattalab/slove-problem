// accepted
# include <iostream>
# include <string.h>
using namespace std;
int main()
{
    int J,R, num;
    int player[500]; // calculate the sum of victory points
    while(cin >> J >> R && (J && R))
    {
        int max = -1, idx;
        memset(player, 0 , 500*sizeof(int)); // reset to zero
        for(int i=0;i<R;i++) // play R round
        {
            for(int k=0;k<J;k++) // each round, every player play
            {
                cin >> num;
                player[k] += num;
                if (player[k] >= max) // update max
                {
                    max = player[k];
                    idx = k; // record the last player win the maximum victory points
                }
            }
        }
        cout << idx+1 <<endl; // output who wins (player number)
    }
    return 0;
}