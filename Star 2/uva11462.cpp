// accepted
# include <iostream>
using namespace std;
# define Size 105
int main()
{
    int n;
    while (cin >> n && n)
    {
        int num;
        // counting sort
        int age[Size] = {0};
        for(int i=0;i<n;i++) // count frequency
        {
            cin >> num;
            age[num]++;
        }

        bool space = false;
        for(int i=0;i<Size;i++)
        {
            for(int j=0;j<age[i];j++) // output corresponding output
            {
                if (space)
                    cout << " ";

                cout << i ;
                space = true;
            }
        }
        cout << endl;
    }
    
    return 0;
}