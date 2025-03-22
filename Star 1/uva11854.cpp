// accepted
# include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    while(cin >> a >> b >> c && (a && b && c))
    {
        // let c be the maximum length first
        if (a > c && a > b)
        {
            int temp = c;
            c = a;
            a = temp;
        }
        else if (b > c && b > a)
        {
            int temp = b;
            b= c;
            c = temp;
        }
        // 畢氏定理
        int square = a*a + b*b , slope = c*c;
        if (square == slope)
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
    }
    return 0;
}