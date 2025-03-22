// accept
// 依順序排好，一次交換兩個車廂 -> bubble sort
# include <iostream>
using namespace std;
int main()
{
    int N,L;
    cin>> N; // N case
    while(N--)
    {
        cin >> L; // train length
        int arr[L];
        for(int i =0;i<L;i++)
        {
            cin>> arr[i]; // train number
        }

        int count =0; // count swap time
        for (int i=0;i<L-1;i++) // bubble sort
        {
            for(int j =0;j<L-1-i;j++)
            {
                if (arr[j] > arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;

                    count ++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", count);
    }
    return 0;
}