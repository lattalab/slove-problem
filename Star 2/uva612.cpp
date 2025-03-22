# include <iostream>
# include <algorithm>
using namespace std;
struct DNA{
    string s; // record DNA sequence
    int id; // input sequence number
    int rate; // unsortedness
};
int unsortedness(DNA &a) // by promblem definition
{
    int sum=0;
    for(int i=0;i<a.s.length();i++)
    {
        for(int j=i+1;j<a.s.length();j++)
        {
            if (a.s[j] < a.s[i])
                sum += 1;
        }
    }
    return sum;
}
int cmp(DNA &a, DNA &b) // how to sort the DNA unsortedness
{
    if (a.rate == b.rate)
    {
        return a.id < b.id;
    }
    return a.rate < b.rate;
}
int main()
{
    int t,n,m;
    bool flag = false;
    cin >> t;
    while(t--)
    {
        if (flag) // blank line between consecutive case
            cout << endl;
        
        // input
        cin >> n >> m;
        DNA arr[m];
        for(int i=0;i<m;i++)
        {
            cin >> arr[i].s;
            arr[i].id = i+1;
            arr[i].rate = unsortedness(arr[i]);
        }

        sort(arr, arr+m, cmp);

        // output
        for(int i=0;i<m;i++)
            cout << arr[i].s << endl;

        flag = true;
    }
    return 0;
}