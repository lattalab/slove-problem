// accepted
# include <iostream>
using namespace std;
int gcd(int a, int b) // 輾轉相除法
{
    if (b==0)
        return a;
    return gcd(b,a%b);
}
int binary_to_ten(string s)
{
    int num=0 , t = 1;
    for(int i=s.length()-1 ;i>=0; i--)
    {
        num += (s[i]-'0') * t;
        t *=2;
    }
    return num;
}
int main()
{
    int N, pair =1;
    cin >> N;
    while(N--)
    {
        string s1,s2;
        cin >> s1 >> s2;

        cout << "Pair #"<< pair <<": ";
        pair ++;
        int num = gcd(binary_to_ten(s1), binary_to_ten(s2));
        if(num!=1)
            cout << "All you need is love!" << endl;
        else
            cout << "Love is not all you need!" << endl;
    }
    return 0;
}