// accepted
# include <iostream>
# include <string>
using namespace std;
int main()
{
    int n;
    while(cin >> n && n)
    {
        int arr[] = {1,2,3,4,5,6}; // 頂 北 西 東 南 底
        while(n--)
        {
            string s;
            cin >> s;
            if (s.compare("north") == 0)
            {
                arr[1] = arr[0]; // 新北邊變現在頂部
                arr[0] = arr[4]; // 新頂部變現在南邊
                arr[5] = 7-arr[0];
                arr[4] = 7-arr[1];
            }
            if (s.compare("west") == 0)
            {
                arr[2] = arr[0]; //新西邊變現在頂部
                arr[0] = arr[3]; //新頂部變現在東邊
                arr[5] = 7-arr[0];
                arr[3] = 7-arr[2];
            }
            if (s.compare("east") == 0)
            {
                arr[3] = arr[0]; //新東邊變現在頂部
                arr[0] = arr[2]; //新頂部變現在西邊
                arr[5] = 7-arr[0];
                arr[2] = 7-arr[3];
            }
            if (s.compare("south") == 0)
            {
                arr[4] = arr[0]; //新南邊變現在頂部
                arr[0] = arr[1]; //新頂部變現在北邊
                arr[1] = 7-arr[4];
                arr[5] = 7-arr[0];
            }

        }
        cout << arr[0] << endl;
    }
}