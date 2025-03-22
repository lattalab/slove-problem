// accepted
# include <iostream>
using namespace std;
int main()
{
    int n,m, k=1;
    bool flag =0;
    while (cin >> n && cin >> m && (n && m))
    {
        if (flag)
            std::cout << endl;

        char map [n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin >> map[i][j];
        }

        std::cout << "Field #" << k << ":\n";
        k++; flag =1;
        for (int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int count =0;
                if (map[i][j] == '*')
                {
                    std::cout << "*";
                    continue;
                }   

                if (i-1>=0 && j-1 >=0)
                {
                    if (map[i-1][j-1] == '*')
                    count ++;
                }
                if (i-1>=0 && j >=0)
                {
                    if (map[i-1][j] == '*')
                    count ++;
                }
                if (i-1>=0 && j+1 <m)
                {
                    if (map[i-1][j+1] == '*')
                    count ++;
                }
                if (i>=0 && j-1 >=0)
                {
                    if (map[i][j-1] == '*')
                    count ++;
                }
                if (i>=0 && j+1 <m)
                {
                    if (map[i][j+1] == '*')
                    count ++;
                }
                if (i+1<n && j-1 >=0)
                {
                    if (map[i+1][j-1] == '*')
                    count ++;
                }
                if (i+1<n && j >=0)
                {
                    if (map[i+1][j] == '*')
                    count ++;
                }
                if (i+1<n && j+1 <m)
                {
                    if (map[i+1][j+1] == '*')
                    count ++;
                }

                std::cout << count;
            }
            std::cout << endl;   
        }
    }
    return 0;
}