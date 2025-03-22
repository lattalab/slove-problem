// accepted
# include <iostream>
using namespace std;
int f91(int n) 
{
    if (n >= 101)
        return n-10;
    // 事實上n <= 100 會一直遞迴得到91
    return f91(f91(n+11));
}
int main()
{
    int n;
    while(cin >> n && n)
    {
        int num = f91(n);
        printf("f91(%d) = %d\n", n , num);
    }
    return 0;
}